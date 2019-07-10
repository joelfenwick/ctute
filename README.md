ctute
=====

A tutorial and refresher on C, in particular C using the Linux command line environment.

## Design principles (repeated in main.tex)
- this is not intended to be a textbook - it is supposed to support lectures or other resources
- it is intended to be usable (if not optimal) as both a reference and as a tutorial
- forward concept references are to be avoided.  If something is presented as an example which
  readers are supposed to learn from, then they should be able to understand everything in that example.
  That is not to say concept explanations can\'t be iterated/elaborated on later
- System/environment specific details should be separated into their own files so they can be disabled/switched out.
- Except for small fragments, hypreref link to programs so they can be placed elsewhere in the document/floated.
- Only use widely available LaTeX packages - distributed with or auto download for most major LaTeX distributions.
  Think you need to add a class or package to this repo, please think again.
- Content is to be restricted to standard-C99

## Building
Compile the document with `pdflatex main.tex`.
To fill out the table of contents, and other references within the document, compile twice instead of once.
