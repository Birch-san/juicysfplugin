#!/usr/bin/env bash
set -eo pipefail

cd win32metadata/generation/WinSDK/RecompiledIdlHeaders/um
rename 'y/A-Z/a-z/' *
cd ../shared
rename 'y/A-Z/a-z/' *
cd ../winrt
rename 'y/A-Z/a-z/' *
cd ..

find . -type f -exec sed -i 's/OAIdl.idl/oaidl.idl/g' {} \;
find . -type f -exec sed -i 's/OCIdl.idl/ocidl.idl/g' {} \;

# find . | grep '\.idl' | xargs -n1 -I '{}' sh -c 'echo "compiling {}"; widl -D__midl=501 -I../um -I../shared -I../winrt {}'
declare -a idls=(uiautomationcore oaidl oleacc objidl unknwn wtypes unknwnbase wtypesbase)
for idl in "${idls[@]}"
do
  echo "Compiling $idl"
  widl -D__midl=501 -I../um -I../shared -I../winrt "$idl.idl"
done