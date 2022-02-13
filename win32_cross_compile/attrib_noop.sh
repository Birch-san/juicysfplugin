#!/usr/bin/env bash
# attrib is a win32 executable used for modifying file attributes.
# the JUCE build uses it to apply a folder icon to the VST3 folder.
# we can run attrib.exe in Wine, but for aarch64 Ubuntu that entails
# building Wine from source.
# alternatively we could use the Unix utility fattr.
# but we would need to do this on a FAT or NTFS filesystem.
# this is quite high-effort just for the sake of putting an icon on a folder.
>&2 echo "Skipping execution of attrib, with args $@"