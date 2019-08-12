//
//  Model.cpp
//  Lazarus
//
//  Created by Alex Birch on 01/09/2017.
//
//

#include "TableComponent.h"
#include "Util.h"
#include <functional>
#include <iterator>
#include <map>

using namespace std;
using namespace Util;

//==============================================================================
/**
    This class shows how to implement a TableListBoxModel to show in a TableListBox.
*/
TableComponent::TableComponent(
    AudioProcessorValueTreeState& valueTreeState
)
: valueTreeState{valueTreeState}
, font{14.0f}
{
    // Create our table component and add it to this component..
    addAndMakeVisible (table);
    table.setModel (this);

    // give it a border
    table.setColour (ListBox::outlineColourId, Colours::grey);
    table.setOutlineThickness (1);

    int columnIx = 1;

    table.getHeader().addColumn (
            String("#"),
            columnIx++,
            30, // column width
            30, // min width
            400, // max width
            TableHeaderComponent::defaultFlags
    );
    table.getHeader().addColumn (
            String("Name"),
            columnIx++,
            200, // column width
            30, // min width
            400, // max width
            TableHeaderComponent::defaultFlags
    );

    table.setWantsKeyboardFocus(false);

    ValueTree banks{valueTreeState.state.getChildWithName("banks")};
    loadModelFrom(banks);

    // we could now change some initial settings..
    table.getHeader().setSortColumnId(1, false); // sort ascending by ID column
    valueTreeState.state.addListener(this);
    valueTreeState.addParameterListener("bank", this);
    valueTreeState.addParameterListener("preset", this);
}

TableComponent::~TableComponent() {
    valueTreeState.removeParameterListener("bank", this);
    valueTreeState.removeParameterListener("preset", this);
    valueTreeState.state.removeListener(this);
}

void TableComponent::loadModelFrom(ValueTree& banks) {
    banksToPresets.clear();
    int banksChildren{banks.getNumChildren()};
    for(int bankIx{0}; bankIx<banksChildren; bankIx++) {
        ValueTree bank{banks.getChild(bankIx)};
        int bankNum{bank.getProperty("num")};
        int bankChildren{bank.getNumChildren()};
        for(int presetIx{0}; presetIx<bankChildren; presetIx++) {
            ValueTree preset{bank.getChild(presetIx)};
            int presetNum{preset.getProperty("num")};
            String presetName = preset.getProperty("name");
            TableRow row{presetNum, move(presetName)};
            banksToPresets.emplace(bankNum, move(row));
        }
    }
    repopulateTable();
}

void TableComponent::parameterChanged(const String& parameterID, float newValue) {
    if (parameterID == "bank") {
        repopulateTable();
    } else if (parameterID == "preset") {
        selectCurrentPreset();
    }
}

void TableComponent::repopulateTable() {
    rows.clear();
    RangedAudioParameter *param{valueTreeState.getParameter("bank")};
    jassert(dynamic_cast<AudioParameterInt*>(param) != nullptr);
    AudioParameterInt* castParam{dynamic_cast<AudioParameterInt*>(param)};
    int bank{castParam->get()};

    BanksToPresets::iterator lowerBound{banksToPresets.lower_bound(bank)};
    BanksToPresets::iterator upperBound{banksToPresets.upper_bound(bank)};
    
    // basic syntaxes for a lambda which return's a pair's .second
    // https://stackoverflow.com/questions/2568194/populate-a-vector-with-all-multimap-values-with-a-given-key
    // shorter syntax with mem_fn()
    // https://stackoverflow.com/a/36775400/5257399
    transform(
        lowerBound,
        upperBound,
        back_inserter(rows),
        mem_fn(&BanksToPresets::value_type::second)
        );
    table.deselectAllRows();
    table.updateContent();
    table.getHeader().setSortColumnId(0, true);
    selectCurrentPreset();
    table.repaint();
}

void TableComponent::valueTreePropertyChanged(
    ValueTree& treeWhosePropertyHasChanged,
    const Identifier& property) {
    if (treeWhosePropertyHasChanged.getType() == StringRef("banks")) {
        if (property == StringRef("synthetic")) {
            loadModelFrom(treeWhosePropertyHasChanged);
        }
    }
}

// This is overloaded from TableListBoxModel, and must return the total number of rows in our table
int TableComponent::getNumRows()
{
    return static_cast<int>(rows.size());
}

// This is overloaded from TableListBoxModel, and should fill in the background of the whole row
void TableComponent::paintRowBackground (
        Graphics& g,
        int rowNumber,
        int /*width*/,
        int /*height*/,
        bool rowIsSelected
) {
    const Colour alternateColour (getLookAndFeel().findColour (ListBox::backgroundColourId)
            .interpolatedWith (getLookAndFeel().findColour (ListBox::textColourId), 0.03f));
    if (rowIsSelected)
        g.fillAll (Colours::lightblue);
    else if (rowNumber % 2)
        g.fillAll (alternateColour);
}

String TableRow::getStringContents(int columnId) {
    if (columnId <= 1) {
        return String(preset);
    }
    return name;
}

// This is overloaded from TableListBoxModel, and must paint any cells that aren't using custom
// components.
void TableComponent::paintCell (
        Graphics& g,
        int rowNumber,
        int columnId,
        int width,
        int height,
        bool /*rowIsSelected*/
) {
    g.setColour (getLookAndFeel().findColour (ListBox::textColourId));
    g.setFont (font);

	if (rowNumber < rows.size()) {
		TableRow& row{ rows[rowNumber] };
		String text{ row.getStringContents(columnId) };
		g.drawText(text, 2, 0, width - 4, height, Justification::centredLeft, true);
	}

    g.setColour (getLookAndFeel().findColour (ListBox::backgroundColourId));
    g.fillRect (width - 1, 0, 1, height);
}

// This is overloaded from TableListBoxModel, and tells us that the user has clicked a table header
// to change the sort order.
void TableComponent::sortOrderChanged (
        int newSortColumnId,
        bool isForwards
) {
    if (newSortColumnId != 0) {
        TableComponent::DataSorter sorter (newSortColumnId, isForwards);
        sort(rows.begin(), rows.end(), sorter);

        table.updateContent();
        selectCurrentPreset();
    }
}

void TableComponent::selectCurrentPreset() {
    table.deselectAllRows();
    RangedAudioParameter *param{valueTreeState.getParameter("preset")};
    jassert(dynamic_cast<AudioParameterInt*>(param) != nullptr);
    AudioParameterInt* castParam{dynamic_cast<AudioParameterInt*>(param)};
    int value{castParam->get()};

    for (auto it{rows.begin()}; it != rows.end(); ++it) {
        if(it->preset == value) {
            int index{static_cast<int>(distance(rows.begin(), it))};
            table.selectRow(index);
            break;
        }
    }
}

// This is overloaded from TableListBoxModel, and should choose the best width for the specified
// column.
int TableComponent::getColumnAutoSizeWidth (int columnId) {
    if (columnId == 1)
        return 30;

    
    int widest = 32;

    // find the widest bit of text in this column..
    for (int i{getNumRows()}; --i >= 0;) {
        TableRow& row{rows[i]};
        String text{row.getStringContents(columnId)};
        widest = jmax (widest, font.getStringWidth (text));
    }

    return widest + 8;
}

//==============================================================================
void TableComponent::resized() {
    // position our table with a gap around its edge
    table.setBoundsInset (BorderSize<int> (7));
}

//==============================================================================
// A comparator used to sort our data when the user clicks a column header

TableComponent::DataSorter::DataSorter (
        int columnByWhichToSort,
        bool forwards
)
: columnByWhichToSort (columnByWhichToSort)
, direction (forwards ? 1 : -1)
{}

bool TableComponent::DataSorter::operator ()(
        TableRow first,
        TableRow second
) {
    int result;
    if (columnByWhichToSort <= 1) {
        result = compare(first.preset, second.preset);
    } else {
        result = first.name
            .compareNatural (second.name);
        if (result == 0) {
            result = compare(first.preset, second.preset);
        }
    }

    result *= direction;

    return result > 0;
}

void TableComponent::selectedRowsChanged (int row) {
    if (row < 0) {
        return;
    }
    int newPreset{rows[row].preset};
    RangedAudioParameter *param{valueTreeState.getParameter("preset")};
    jassert(dynamic_cast<AudioParameterInt*>(param) != nullptr);
    AudioParameterInt* castParam{dynamic_cast<AudioParameterInt*>(param)};
    *castParam = newPreset;
}

bool TableComponent::keyPressed(const KeyPress &key) {
    return table.keyPressed(key);
}

TableRow::TableRow(
    int preset,
    String name
)
: preset{preset}
, name{name}
{}
