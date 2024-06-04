set shell := ["fish", "-c"]
set positional-arguments

kb := "splitkb/kyria/rev3"
km := "indianboy42"

qmk := "qmk"

export LDFLAGS := ""
# qmk := "./bin/qmk"
# qmk := "just nix"

# First/Default command:
# Compile a keyboard
flash:
    {{qmk}} flash -kb {{kb}} -km {{km}}


# Run qmk inside a nix-shell
nix *arguments:
    nix-shell --pure --command "qmk $argv"

# Run arbitrary make command
make *arguments:
    make {{arguments}}

# Check qmk installation
doctor:
    {{qmk}} doctor

# Compile a keyboard
compile:
    {{qmk}} compile -kb {{kb}} -km {{km}}

edit:
    $EDITOR {{justfile_directory()}}/indianboy42/keymap_common.h {{justfile_directory()}}/keyboards/{{kb}}/keymaps/{{km}}/keymaps.c

upstream:
    #!/usr/bin/env bash
    HASH=$(git rev-parse master)
    git branch master-$HASH $HASH
    git checkout master
    git rebase upstream/master

compile_commands:
    qmk generate-compilation-database -kb {{kb}} -km {{km}}

save-config:
    qmk config user.keyboard={{kb}}
    qmk config user.keymap={{km}}
