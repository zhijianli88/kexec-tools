#ifndef KEXEC_ARCH_PPC64_OPTIONS_H
#define KEXEC_ARCH_PPC64_OPTIONS_H

#define OPT_ELF64_CORE		(OPT_MAX+0)
#define OPT_DT_NO_OLD_ROOT	(OPT_MAX+1)
#define OPT_ARCH_MAX		(OPT_MAX+2)

/* All 'local' loader options: */
#define OPT_APPEND		(OPT_ARCH_MAX+0)
#define OPT_RAMDISK		(OPT_ARCH_MAX+1)
#define OPT_DEVICETREEBLOB	(OPT_ARCH_MAX+2)
#define OPT_ARGS_IGNORE		(OPT_ARCH_MAX+3)
#define OPT_REUSE_CMDLINE	(OPT_ARCH_MAX+4)

/* Options relevant to the architecture (excluding loader-specific ones): */
#define KEXEC_ARCH_OPTIONS \
	KEXEC_OPTIONS \
	{ "elf64-core-headers", 0, 0, OPT_ELF64_CORE }, \
	{ "dt-no-old-root",	0, 0, OPT_DT_NO_OLD_ROOT }, \

#define KEXEC_ARCH_OPT_STR KEXEC_OPT_STR ""

/* The following two #defines list ALL of the options added by all of the
 * architecture's loaders.
 * o	main() uses this complete list to scan for its options, ignoring
 *	arch-specific/loader-specific ones.
 * o	Then, arch_process_options() uses this complete list to scan for its
 *	options, ignoring general/loader-specific ones.
 * o	Then, the file_type[n].load re-scans for options, using
 *	KEXEC_ARCH_OPTIONS plus its loader-specific options subset.
 *	Any unrecognised options cause an error here.
 *
 * This is done so that main()'s/arch_process_options()'s getopt_long() calls
 * don't choose a kernel filename from random arguments to options they don't
 * recognise -- as they now recognise (if not act upon) all possible options.
 */
#define KEXEC_ALL_OPTIONS \
	KEXEC_ARCH_OPTIONS				\
	{ "command-line",       1, NULL, OPT_APPEND },	\
	{ "append",             1, NULL, OPT_APPEND },	\
	{ "ramdisk",            1, NULL, OPT_RAMDISK },	\
	{ "initrd",             1, NULL, OPT_RAMDISK },		\
	{ "devicetreeblob",     1, NULL, OPT_DEVICETREEBLOB },	\
	{ "dtb",                1, NULL, OPT_DEVICETREEBLOB },	\
	{ "args-linux",         0, NULL, OPT_ARGS_IGNORE },	\
	{ "reuse-cmdline",      0, NULL, OPT_REUSE_CMDLINE },

#define KEXEC_ALL_OPT_STR KEXEC_OPT_STR


#endif /* KEXEC_ARCH_PPC64_OPTIONS_H */
