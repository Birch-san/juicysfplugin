//
// Created by Alex Birch on 01/10/2017.
//

#include "Pill.h"

Pill::Pill(
        const String& buttonName,
        const int index,
        const int lastIx
) : TextButton(buttonName) {
    setBounds(20 + index * 55, 260, 55, 24);
    setConnectedEdges (
            (index == 0 ? 0 : Button::ConnectedOnLeft)
            | (index == lastIx ? 0 : Button::ConnectedOnRight)
    );
}