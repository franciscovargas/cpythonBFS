from distutils.core import setup, Extension

spam_module = Extension('bfs_c',
		sources = ['src/bfs.cpp'],
		extra_compile_args=['-std=c++11', '-O3', '-march=native'])

setup ( name = 'bfs',
	version = '1.0',
	description = 'Sample module.',
	ext_modules = [ spam_module ])

