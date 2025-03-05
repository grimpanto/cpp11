from pathlib import Path
import contextlib, os
import shutil
import itertools

from invoke import run, task, executor

contents_dir = Path("contents/").resolve()
layout_dir = Path("layout/").resolve()
build_dir = Path("build/").resolve()
scripts_dir = Path("scripts/").resolve()

filter_file = scripts_dir / "filter.py"
main_file = build_dir / "prod_book.tex"
template_file = layout_dir / "pandoc" / "comp.context"
bib_file = contents_dir / "bibliography.bib"

"""
-t context: to context
--smart: Behandlung von ---, --, ... und Leerzeichen nach Mr. (standard für ConTeXt)
-s: standalone, damit mein pandoc-Template genommen wird
--chapters: bewirkt, dass Kapitel für erste
--template file: eigene Template-Datei
"""
#              " --bibliography={}"\
#              " --csl=din-1505-2.csl"\

pandoc_options = "-f markdown+header_attributes -t context --smart -s --chapters"
pandoc_call = "pandoc {} --template {}"\
              " --filter {}".format(pandoc_options,
                                    template_file,
                                    filter_file)

@contextlib.contextmanager
def cd(new_dir):
    curr_dir= os.getcwd()
    os.chdir(new_dir)
    try: yield
    finally: os.chdir(curr_dir)


@task
def clean():
    with cd("build"):
        run("rm *.tex *.tuc *.html *.log", warn=True, hide=True)
    init()


@task
def distclean():
    with cd("build"):
        run("rm *", warn=True, hide=True)


@task
def pandoc():
    md_files = contents_dir.glob("*.md")
    with cd("build"):
        for f in md_files:
            comp = "comp_" + f.stem
            tex_file = comp + ".tex"
            run(pandoc_call +
                " -V 'comp={}' {} -o {}".format(comp, f, tex_file))


@task
def init():
    tex_files = layout_dir.glob("*.tex")
    for f in tex_files:
        shutil.copy(str(f), "build")


@task
def context(component=None):
    tex_files = contents_dir.glob("*.tex")
    bib_files = contents_dir.glob("*.bib")
    for f in itertools.chain(tex_files,bib_files):
        shutil.copy(str(f), "build")

    with cd("build"):
        run("context --smart {}".format(component if component else main_file))


@task
def all():
    init()
    pandoc()
    context()
