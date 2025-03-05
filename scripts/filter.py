#!/usr/bin/env python

"""
Pandoc filter to convert code blocks with class="cpp" (or "java" or "python")
to ConTeXt vim typing in ConTeXt output.
"""

import sys

from pandocfilters import toJSONFilter, RawBlock, RawInline, Para, Div#, CodeBlock, Para


def context(x):
  return RawBlock('context',x)


def filtering(key, value, format, meta):
    if key == 'CodeBlock':
        [[ident,classes,kvs], contents] = value
        # print(format, file=sys.stderr)
        # print(classes, file=sys.stderr)
        # print(ident, file=sys.stderr)
        # print(contents, file=sys.stderr)
        # print(file=sys.stderr)
        if format == "context":
            lang = ""
            if "cpp" in classes:
                lang = "cpp"
            if "java" in classes:
                lang = "java"
            if "python" in classes:
                lang = "python"
            if "sh" in classes:
                lang = "sh"
            if lang:
                #if ident == "":
                #    label = ""
                #else:
                #    label = '\\label{' + ident + '}'
                return RawBlock("context",
                    '\\start' + lang + '\n' +#+ label
                            contents + '\n\\stop' + lang)
    elif key == 'Cite':
        if format == "context":
            for lst in value:
                for cite in lst:
                    if 'citationId' in cite:
                        return RawInline("context", "\\cite[" + cite["citationId"] + "]")

#    elif key == "Header":
#        #[[ident,classes], contents] = value
#        print(value, file=sys.stderr)

    elif key == 'Div':
        [[ident,classes,kvs], contents] = value
        cls = ""
        if "annotation" in classes:
            cls = "annotation"
        elif "drawer" in classes:
            cls = "drawer"
        elif "excerpt" in classes:
            cls = "excerpt"
        elif "tipp" in classes:
            cls = "tipp"
        elif "thumb" in classes:
            cls = "thumb"
        elif "c++14" in classes:
            cls = "c++14"
            

        if format == "context":
            if cls == "annotation":
                title = "Bemerkung"
                for item in kvs:
                    if item[0] == 'title':
                        title = item[1]
                        print(title, file=sys.stderr)
                if title:
#                    print(contents, file=sys.stderr)
#                    print(file=sys.stderr)
                    return Para([RawInline('context',
                                        '\\startannotation{' + title + '}')] +
                        contents[0]['c'] +
                        [RawInline('context', '\\stopannotation')])
                else:
                    return Para([RawInline('context',
                                        '\\startannotation ')] +
                        contents[0]['c'] +
                        [RawInline('context', '\\stopannotation')])
            elif cls == "tipp":
                return [RawBlock('context', '\\startannotation{Tipp}')] +\
                    contents +\
                    [RawBlock('context', '\\stopannotation')]
            elif cls == "thumb":
                return [RawBlock('context', '\\startannotation{Faustregel}')] +\
                    contents +\
                    [RawBlock('context', '\\stopannotation')]
            elif cls == "c++14":
                return [RawBlock('context', '\\startannotation{\cppXIV}')] +\
                    contents +\
                    [RawBlock('context', '\\stopannotation')]
            elif cls == "drawer":
               return [RawBlock('context', '\\startdrawer')] +\
                    contents +\
                    [RawBlock('context', '\\stopdrawer')]
            elif cls == "excerpt":
                for item in kvs:
                    if item[0] == 'source':
                        source = item[1]
                        print(source, file=sys.stderr)
                return Para([RawInline('context',
                  '\\startexcerpt{' + source + '}')]
                    + contents[0]['c'] +
                    [RawInline('context', '\\stopexcerpt')])


if __name__ == "__main__":
    toJSONFilter(filtering)
