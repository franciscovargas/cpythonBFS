from distutils.core import setup, Extension

spam_module = Extension('spam',
		sources = ['spammodule.cpp'],
		extra_compile_args=['-std=c++11'])

setup ( name = 'Spam',
	version = '1.0',
	description = 'Sample module.',
	ext_modules = [ spam_module ])

