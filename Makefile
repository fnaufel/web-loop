
Cfiles  = src/shell.c
JSfile = www/shell.js
WASMfile = www/shell.wasm

all : $(JSfile)

$(JSfile) : $(Cfiles)
			emcc $(Cfiles) -o $(JSfile) -sEXPORTED_FUNCTIONS=_process_command -sEXPORTED_RUNTIME_METHODS=ccall,cwrap

clean :
		rm $(JSfile) $(WASMfile)
