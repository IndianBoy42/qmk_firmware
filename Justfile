set shell := ["fish", "-c"]
set positional-arguments

kb := "tg4x"
km := "indianboy42"

qmk := "qmk"
# qmk := "./bin/qmk"
# qmk := "just nix"

# Run qmk inside a nix-shell
nix *arguments:
    nix-shell --pure --command "qmk $argv"

# Check qmk installation
doctor:
    {{qmk}} doctor

# Compile a keyboard
compile:
    {{qmk}} compile -kb {{kb}} -km {{km}}

# Compile a keyboard
flash: compile
    {{qmk}} flash -kb {{kb}} -km {{km}}

