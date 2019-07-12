//
//  Model.hpp
//  Lazarus
//
//  Created by Alex Birch on 01/09/2017.
//
//

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PresetsToBanks.h"
#include <memory>
#include <string>

using namespace std;

class TableComponent    : public Component,
                          public TableListBoxModel,
                          public ValueTree::Listener/*,
                          public AudioProcessorValueTreeState::Listener */ {
public:
    TableComponent(
            AudioProcessorValueTreeState& valueTreeState,
        //     const vector<string> &columns,
            const vector<vector<string>> &rows,
            const function<void (int)> &onRowSelected,
        //     const function<int (const vector<string>&)> &rowToIDMapper,
            int initiallySelectedRow
    );
    ~TableComponent();

    int getNumRows() override;

    void paintRowBackground (
            Graphics& g,
            int rowNumber,
            int width,
            int height,
            bool rowIsSelected
    ) override;
    void paintCell (
            Graphics& g,
            int rowNumber,
            int columnId,
            int width,
            int height,
            bool rowIsSelected
    ) override;

    void sortOrderChanged (int newSortColumnId, bool isForwards) override;

    int getColumnAutoSizeWidth (int columnId) override;

    void selectedRowsChanged (int row) override;

    void resized() override;

    void setRows(const vector<vector<string>>& rows, int initiallySelectedRow);

    bool keyPressed(const KeyPress &key) override;

//     virtual void parameterChanged (const String& parameterID, float newValue) override;

    virtual void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged,
                                           const Identifier& property) override;
    inline virtual void valueTreeChildAdded (ValueTree& parentTree,
                                             ValueTree& childWhichHasBeenAdded) override {};
    inline virtual void valueTreeChildRemoved (ValueTree& parentTree,
                                               ValueTree& childWhichHasBeenRemoved,
                                               int indexFromWhichChildWasRemoved) override {};
    inline virtual void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved,
                                                    int oldIndex, int newIndex) override {};
    inline virtual void valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged) override {};
    inline virtual void valueTreeRedirected (ValueTree& treeWhichHasBeenChanged) override {};
private:
    AudioProcessorValueTreeState& valueTreeState;

    TableListBox table;     // the table component itself
    Font font;

    vector<string> columns;
    vector<vector<string>> rows;

    function<void (int)> onRowSelected;
//     function<int (const vector<string>&)> rowToIDMapper;

    // A comparator used to sort our data when the user clicks a column header
    class DataSorter {
    public:
        DataSorter (
                int columnByWhichToSort,
                bool forwards
        );

        bool operator ()(
                vector<string> first,
                vector<string> second
        );

    private:
        int columnByWhichToSort;
        int direction;
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TableComponent)
};