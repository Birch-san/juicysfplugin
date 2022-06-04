#!/usr/bin/env bash
LISTS=( /etc/apt/sources.list /etc/apt/sources.list.d/proposed.list )
for LIST in "${LISTS[@]}"
do
  TMPFILE="$(mktemp)"
  awk '$1 ~ /^deb$/ && $2 ~ /^http:\/\/ports.ubuntu.com\// {
  $1=$1" [arch=arm64]"
}
$1 ~ /^deb$/ && $2 ~ /^http:\/\/(archive|security).ubuntu.com\// {
  $1=$1" [arch=amd64,i386]"
}
{ print $0 }' "$LIST" > "$TMPFILE"
  mv "$TMPFILE" "$LIST"
done
. /etc/lsb-release

declare -A ARCHIVE_ARCHS=( [amd64]=1 [i386]=1 )
declare -A PORTS_ARCHS=( [arm64]=1 )
ARCH="$(dpkg --print-architecture)"

if [[ ! ${ARCHIVE_ARCHS["$ARCH"]} ]] ; then
  TARGET_ARCHS='amd64,i386'
  ARCHIVE='http://archive.ubuntu.com/ubuntu/'
  SECURITY='http://security.ubuntu.com/ubuntu/'
  echo "deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME main restricted
deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME-updates main restricted
deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME universe
deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME-updates universe
deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME multiverse
deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME-updates multiverse
deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME-backports main restricted universe multiverse
deb [arch=$TARGET_ARCHS] $SECURITY $DISTRIB_CODENAME-security main restricted
deb [arch=$TARGET_ARCHS] $SECURITY $DISTRIB_CODENAME-security universe
deb [arch=$TARGET_ARCHS] $SECURITY $DISTRIB_CODENAME-security multiverse" >> /etc/apt/sources.list
  echo "deb [arch=$TARGET_ARCHS] $ARCHIVE $DISTRIB_CODENAME-proposed main restricted" >> /etc/apt/sources.list.d/proposed.list
  dpkg --add-architecture amd64
  dpkg --add-architecture i386
fi
if [[ ! ${PORTS_ARCHS["$ARCH"]} ]]; then
  TARGET_ARCHS='arm64'
  REPO='http://ports.ubuntu.com/ubuntu-ports/'
  echo "deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME main restricted
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-updates main restricted
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME universe
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-updates universe
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME multiverse
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-updates multiverse
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-backports main restricted universe multiverse
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-security main restricted
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-security universe
deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-security multiverse" >> /etc/apt/sources.list
  echo "deb [arch=$TARGET_ARCHS] $REPO $DISTRIB_CODENAME-proposed main restricted" >> /etc/apt/sources.list.d/proposed.list
  dpkg --add-architecture arm64
fi