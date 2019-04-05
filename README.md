# Digraph

Parse vim-style digraphs in text streams.

## Description

One of the many cool features of [vim](https://vim.org) is the ability to input character digraphs directly in the editor using `C-k`. This program aims at providing the same functionality outside of the editor.

## Usage

When reading a file or stream, `digraph` looks for a text anchor (defaults to `#`) and tries to combine the two following characters into a digraph. For instance,
```sh
echo "Fatigu#'e" | digraph
``` 

will result in `Fatigué`.

If no digraphs are found, the first of the two characters is returned.

## Disclaimer

This project reuses most of the features found in vim's [digraph.c](https://github.com/vim/vim/blob/master/src/digraph.c). Only the RFC1345 set of digraphs is implemented so far.

## License

Distributed under the GPL.
