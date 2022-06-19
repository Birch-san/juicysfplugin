#!/usr/bin/env bash
git clone --depth 1 https://github.com/xiph/opus.git
cd opus
# picking HEAD-of-master commit because it's 3 years newer than the last tagged release
git checkout ccaaffa9a3ee427e9401c4dcf6462e378d9a4694