#!/usr/bin/env bash

# Ascertain directory in which script lives; compatible with all UNIX
# Thanks to kenorb
# http://stackoverflow.com/a/17744637/5257399
MYDIR=$(cd -P -- "$(dirname -- "$0")" && pwd -P)
set -o pipefail

cd "$MYDIR/licenses_of_dependencies"
cat <(printf "%s\n\n" ">== juicysfplugin (application, VST and VST3): <==") ../../../LICENSE.txt <(find *.txt -type f -print0 | xargs -0 -I {} sh -c 'printf "\n\n>== %s: <==\n\n" {}; cat {}') > "$MYDIR/license_concatenated.txt"