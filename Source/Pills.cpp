//
// Created by Alex Birch on 01/10/2017.
//

#include "Pills.h"
#include "MyColours.h"

using namespace std;

Pill::Pill(
    AudioProcessorValueTreeState& valueTreeState,
    int bank,
    bool isFirst,
    bool isLast
)
// : pills{pills}
: bank{bank}
, textButton{String(bank)}
{
    textButton.setConnectedEdges (
            (isFirst ? 0 : Button::ConnectedOnLeft)
            | (isLast ? 0 : Button::ConnectedOnRight)
    );
    textButton.setRadioGroupId(34567);
    loadToggleState();
    textButton.setClickingTogglesState(true);
    
    valueTreeState.state.addListener(this);
    textButton.addListener(this);
}

Pill::~Pill() {
    valueTreeState.state.removeListener(this);
    textButton.removeListener(this);
}

Pill::loadToggleState() {
    RangedAudioParameter *param {valueTreeState.getParameter("bank")};
    jassert(dynamic_cast<AudioParameterInt*> (param) != nullptr);
    AudioParameterInt* castParam {dynamic_cast<AudioParameterInt*> (param)};
    int value{castParam->get()};
    textButton.setToggleState(value == bank, dontSendNotification);
}

void Pill::buttonClicked (Button* button) {
    // selected = button;
    // onItemSelected(itemToIDMapper(button->getName().toStdString()));
    RangedAudioParameter *param {valueTreeState.getParameter("bank")};
    jassert(dynamic_cast<AudioParameterInt*> (param) != nullptr);
    AudioParameterInt* castParam {dynamic_cast<AudioParameterInt*> (param)};
    *castParam = bank;
}

void Pill::parameterChanged(const String& parameterID, float newValue) {
    if (parameterID == "bank") {
        loadToggleState();
    }
}

void Pill::valueTreePropertyChanged(
    ValueTree& treeWhosePropertyHasChanged,
    const Identifier& property) {
    if (treeWhosePropertyHasChanged.getType() == StringRef("presets")) {
        loadModelFrom(treeWhosePropertyHasChanged);
    }
}

Pills::Pills(
    AudioProcessorValueTreeState& valueTreeState
    // string label,
    // const vector<string> &items,
    // const function<void (int)> &onItemSelected,
    // const function<int (const string&)> &itemToIDMapper,
    // int initiallySelectedItem
)
: valueTreeState{valueTreeState}
// , label{label}
    // items(items),
    // onItemSelected(onItemSelected),
    // itemToIDMapper(itemToIDMapper)
{
    // faster (rounded edges introduce transparency)
    setOpaque (true);

    // populate(initiallySelectedItem);
    loadModelFrom(valueTreeState.state.getChildWithName("banks"));

    valueTreeState.state.addListener(this);
}

Pills::~Pills() {
    valueTreeState.state.removeListener(this);
}

void Pills::valueTreePropertyChanged(
    ValueTree& treeWhosePropertyHasChanged,
    const Identifier& property) {
    if (treeWhosePropertyHasChanged.getType() == StringRef("banks")) {
        loadModelFrom(treeWhosePropertyHasChanged);
    }
}

void Pills::loadModelFrom(ValueTree& banks) {
    pills.clear();
    int numChildren{banks.getNumChildren()};
    for(int i{0}; i < numChildren; i++) {
        ValueTree child{banks.getChild(i)};
        int num{child.getProperty("num")};
        // rows.push_back(unique_ptr<Pill>(new Pill(), [](Pill* pill) {
        //     pill->remo
        // }));
        pills.emplace_back(
            this.valueTreeState,
            num,
            i == 0,
            i == numChildren - 1);
    }
}

// void Pills::populate(int initiallySelectedItem) {
//     int index = 0;
//     for (string item : items) {
//         TextButton* pill = addToList(new TextButton(
//                 item
//         ));
// //        pill->setColour (TextButton::buttonOnColourId, Colours::blueviolet.brighter());
// //        pill->setBounds(20 + index * 55, 260, 55, 24);
//         pill->setConnectedEdges (
//                 (index == 0 ? 0 : Button::ConnectedOnLeft)
//                         | (index == (items.size()-1) ? 0 : Button::ConnectedOnRight)
//         );
//         pill->setRadioGroupId(34567);
//         if (index == initiallySelectedItem) {
//             pill->setToggleState(true, dontSendNotification);
//             selected = pill;
//         }
//         pill->setClickingTogglesState(true);
//         pill->addListener(this);
//         index++;
//     }
// }

// void Pills::setItems(
//         const vector<string> &items,
//         int initiallySelectedItem
// ) {
//     this->items = items;
//     for(TextButton* t : buttons) {
//         t->removeListener(this);
//     }
//     buttons.clear(true);
//     populate(initiallySelectedItem);
//     resized();
// }

// TextButton* Pills::addToList (TextButton* newButton) {
//     buttons.add (newButton);
//     addAndMakeVisible (newButton);
//     return newButton;
// }

void Pills::cycle(bool right) {
    // TODO: base this on valueTree
    int currentIx = static_cast<const int>(distance(pills.begin(), find(pills.begin(), pills.end(), selected)));
    currentIx += right ? 1 : pills.size()-1;
    pills[currentIx % pills.size()]->textButton.triggerClick();
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