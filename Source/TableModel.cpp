//
// Created by Alex Birch on 17/09/2017.
//

#include "TableModel.h"

// This is overloaded from TableListBoxModel, and must return the total number of rows in our table
int TableModel::getNumRows()
{
    return static_cast<int>(dataList.size());
}

// This is overloaded from TableListBoxModel, and should fill in the background of the whole row
void TableModel::paintRowBackground (
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
void TableModel::paintCell (
        Graphics& g,
        int rowNumber,
        int columnId,
        int width,
        int height,
        bool /*rowIsSelected*/
) {
    g.setColour (getLookAndFeel().findColour (ListBox::textColourId));
    g.setFont (font);

    if (const XmlElement* rowElement = dataList->getChildElement (rowNumber))
    {
        const String text (rowElement->getStringAttribute (getAttributeNameForColumnId (columnId)));

        g.drawText (text, 2, 0, width - 4, height, Justification::centredLeft, true);
    }

    g.setColour (getLookAndFeel().findColour (ListBox::backgroundColourId));
    g.fillRect (width - 1, 0, 1, height);
}

// This is overloaded from TableListBoxModel, and tells us that the user has clicked a table header
// to change the sort order.
void TableModel::sortOrderChanged (
        int newSortColumnId,
        bool isForwards
) {
    if (newSortColumnId != 0)
    {
        TableModel::DataSorter sorter (getAttributeNameForColumnId (newSortColumnId), isForwards);
        dataList->sortChildElements (sorter);

        table.updateContent();
    }
}

// This is overloaded from TableListBoxModel, and should choose the best width for the specified
// column.
int TableModel::getColumnAutoSizeWidth (int columnId) {
    if (columnId == 5)
        return 100; // (this is the ratings column, containing a custom combobox component)

    int widest = 32;

    // find the widest bit of text in this column..
    for (int i = getNumRows(); --i >= 0;)
    {
        if (const XmlElement* rowElement = dataList->getChildElement (i))
        {
            const String text (rowElement->getStringAttribute (getAttributeNameForColumnId (columnId)));

            widest = jmax (widest, font.getStringWidth (text));
        }
    }

    return widest + 8;
}