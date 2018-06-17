//
//  Model.cpp
//  Lazarus
//
//  Created by Alex Birch on 01/09/2017.
//
//

#include "TableComponent.h"

using namespace std;

//==============================================================================
/**
    This class shows how to implement a TableListBoxModel to show in a TableListBox.
*/
TableComponent::TableComponent(
        const vector<string> &columns,
        const vector<vector<string>> &rows,
        const function<void (int)> &onRowSelected,
        const function<int (const vector<string>&)> &rowToIDMapper,
        int initiallySelectedRow
)
        : font (14.0f),
          columns(columns),
          rows(rows),
          onRowSelected(onRowSelected),
          rowToIDMapper(rowToIDMapper)
{
    // Create our table component and add it to this component..
    addAndMakeVisible (table);
    table.setModel (this);

    // give it a border
    table.setColour (ListBox::outlineColourId, Colours::grey);
    table.setOutlineThickness (1);

    int columnIx = 1;

    // Add some columns to the table header, based on the column list in our database..
    for (auto &column : columns) // access by reference to avoid copying
    {
        table.getHeader().addColumn (
                String(column),
                columnIx++,
                100, // column width
                50, // min width
                400, // max width
                TableHeaderComponent::defaultFlags
        );
    }

    table.setWantsKeyboardFocus(false);

    table.selectRow(initiallySelectedRow);

    // we could now change some initial settings..
    table.getHeader().setSortColumnId (1, false); // sort ascending by ID column
//    table.getHeader().setColumnVisible (7, false); // hide the "length" column until the user shows it

    // un-comment this line to have a go of stretch-to-fit mode
    // table.getHeader().setStretchToFitActive (true);

//    table.setMultipleSelectionEnabled (false);
}

void TableComponent::setRows(const vector<vector<string>>& rows, int initiallySelectedRow) {
    this->rows = rows;
    table.deselectAllRows();
    table.updateContent();
    table.getHeader().setSortColumnId(0, true);
    table.selectRow(initiallySelectedRow);
    table.repaint();
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

    g.drawText (rows[rowNumber][columnId-1], 2, 0, width - 4, height, Justification::centredLeft, true);

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
        int selectedRowIx = table.getSelectedRow();
        vector<string> selectedRow;
        if (selectedRowIx >= 0) {
            selectedRow = rows[selectedRowIx];
        }

        TableComponent::DataSorter sorter (newSortColumnId, isForwards);
        sort(rows.begin(), rows.end(), sorter);

        table.updateContent();

        if (selectedRowIx >= 0) {
            for (auto it = rows.begin(); it != rows.end(); ++it) {
                if(*it == selectedRow) {
                    int index = static_cast<int>(std::distance(rows.begin(), it));
                    table.selectRow(index);
                    break;
                }
            }
        }
    }
}

// This is overloaded from TableListBoxModel, and should choose the best width for the specified
// column.
int TableComponent::getColumnAutoSizeWidth (int columnId) {
    if (columnId == 5)
        return 100; // (this is the ratings column, containing a custom combobox component)

    int widest = 32;

    // find the widest bit of text in this column..
    for (int i = getNumRows(); --i >= 0;) {
        widest = jmax (widest, font.getStringWidth (rows[i][columnId-1]));
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
        : columnByWhichToSort (columnByWhichToSort),
          direction (forwards ? 1 : -1)
{}

bool TableComponent::DataSorter::operator ()(
        vector<string> first,
        vector<string> second
) {
    int result = String(first[columnByWhichToSort-1])
            .compareNatural (String(second[columnByWhichToSort-1]));

    if (result == 0)
        result = String(first[0])
                .compareNatural (String(second[0]));

    result *= direction;

    return result > 0;
}

void TableComponent::selectedRowsChanged (int row) {
    if (row < 0) {
        return;
    }
    onRowSelected(rowToIDMapper(rows[row]));
}

bool TableComponent::keyPressed(const KeyPress &key) {
    return table.keyPressed(key);
}