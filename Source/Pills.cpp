//
// Created by Alex Birch on 01/10/2017.
//

#include "Pills.h"
#include "MyColours.h"

using namespace std;

Pills::Pills(
        string label,
        const vector<string> &items,
        const function<void (int)> &onItemSelected,
        const function<int (const string&)> &itemToIDMapper,
        int initiallySelectedItem
) : label(label),
    items(items),
    onItemSelected(onItemSelected),
    itemToIDMapper(itemToIDMapper)
{
    // faster (rounded edges introduce transparency)
    setOpaque (true);

    populate(initiallySelectedItem);
}

void Pills::populate(int initiallySelectedItem) {
    int index = 0;
    for (string item : items) {
        TextButton* pill = addToList(new TextButton(
                item
        ));
//        pill->setColour (TextButton::buttonOnColourId, Colours::blueviolet.brighter());
//        pill->setBounds(20 + index * 55, 260, 55, 24);
        pill->setConnectedEdges (
                (index == 0 ? 0 : Button::ConnectedOnLeft)
                        | (index == (items.size()-1) ? 0 : Button::ConnectedOnRight)
        );
        pill->setRadioGroupId(34567);
        if (index == initiallySelectedItem) {
            pill->setToggleState(true, dontSendNotification);
            selected = pill;
        }
        pill->setClickingTogglesState(true);
        pill->addListener(this);
        index++;
    }
}

void Pills::setItems(
        const vector<string> &items,
        int initiallySelectedItem
) {
    this->items = items;
    for(TextButton* t : buttons) {
        t->removeListener(this);
    }
    buttons.clear(true);
    populate(initiallySelectedItem);
    resized();
}

void Pills::buttonClicked (Button* button) {
    selected = button;
    onItemSelected(itemToIDMapper(button->getName().toStdString()));
}

TextButton* Pills::addToList (TextButton* newButton) {
    buttons.add (newButton);
    addAndMakeVisible (newButton);
    return newButton;
}

void Pills::cycle(bool right) {
    int currentIx = static_cast<const int>(distance(buttons.begin(), find(buttons.begin(), buttons.end(), selected)));
    currentIx += right ? 1 : buttons.size()-1;
    buttons[currentIx % buttons.size()]->triggerClick();
}

void Pills::resized() {
    int index = 0;
    Rectangle<int> r (getLocalBounds());
    const int equalWidth = r.proportionOfWidth(buttons.size() <= 0 ? 1.0 : 1.0f/buttons.size());
    for(TextButton* t : buttons) {
        Rectangle<int> r2 (getLocalBounds());
        r2.removeFromLeft(equalWidth * index);
        r2.removeFromRight(equalWidth * (buttons.size()-index-1));
        t->setBounds (r2);
        index++;
    }
}

/**
 * This is required to support setOpaque(true)
 */
void Pills::paint(Graphics& g)
{
    g.fillAll(MyColours::getUIColourIfAvailable(LookAndFeel_V4::ColourScheme::UIColour::windowBackground, Colours::lightgrey));
}