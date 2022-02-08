#!/usr/bin/env bash
# attrib is a win32 executale used for modifying file attributes
# the JUCE build uses it to apply an icon to our exe.
# we can do this in Wine, but Wine doesn't run on aarch64 Linux yet.
# will have to come back for it in a later step.
>&2 echo "Skipping execution of attrib, with args $@"