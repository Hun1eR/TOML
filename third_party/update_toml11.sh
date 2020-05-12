#!/bin/bash

tmpdir=$(mktemp -d)

git clone --depth 1 --recursive --shallow-submodules -b master https://github.com/ToruNiina/toml11.git $tmpdir
ret=$?

if test "$ret" -eq 0
then
    echo
    echo 'Commit:' $(git -C $tmpdir log -1 --format='%H')
    echo 'Author:' $(git -C $tmpdir log -1 --format='%an, %ar')
    echo 'Subject:' $(git -C $tmpdir log -1 --format='%s')
    echo

    mkdir -p "../deps/toml11/include/toml11/toml"
    ret=$?

    if test "$ret" -eq 0
    then
        echo 'Updating TOML11...'

        cp -rf "$tmpdir/toml" "../deps/toml11/include/toml11"
        ret=$?

        if test "$ret" -eq 0
        then
            cp -f "$tmpdir/toml.hpp" "../deps/toml11/include/toml11/toml.hpp"
            ret=$?
        fi

        if test "$ret" -eq 0
        then
            echo 'Successfully completed.'
        fi
    fi
fi

rm -rf $tmpdir

echo
read -p 'Press [Enter] key to exit...'
