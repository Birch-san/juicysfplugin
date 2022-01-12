#!/usr/bin/env bash
exec wine attrib "$1" `winepath --windows "$2"`