include $(top_srcdir)/test/Makefile.inc
TESTS_ENVIRONMENT += TEST_DIR=${top_builddir}/test/validation

ODP_MODULES = pktio \
	      ring \
	      shmem

if test_vald
TESTS = pktio/pktio_run.sh \
	pktio/pktio_run_tap.sh \
	ring/ring_main$(EXEEXT) \
	shmem/shmem_linux \
	${top_builddir}/test/validation/atomic/atomic_main$(EXEEXT) \
	${top_builddir}/test/validation/barrier/barrier_main$(EXEEXT) \
	${top_builddir}/test/validation/buffer/buffer_main$(EXEEXT) \
	${top_builddir}/test/validation/classification/classification_main$(EXEEXT) \
	${top_builddir}/test/validation/cpumask/cpumask_main$(EXEEXT) \
	${top_builddir}/test/validation/crypto/crypto_main$(EXEEXT) \
	${top_builddir}/test/validation/errno/errno_main$(EXEEXT) \
	${top_builddir}/test/validation/hash/hash_main$(EXEEXT) \
	${top_builddir}/test/validation/init/init_main_ok$(EXEEXT) \
	${top_builddir}/test/validation/init/init_main_abort$(EXEEXT) \
	${top_builddir}/test/validation/init/init_main_log$(EXEEXT) \
	${top_builddir}/test/validation/lock/lock_main$(EXEEXT) \
	${top_builddir}/test/validation/packet/packet_main$(EXEEXT) \
	${top_builddir}/test/validation/pool/pool_main$(EXEEXT) \
	${top_builddir}/test/validation/queue/queue_main$(EXEEXT) \
	${top_builddir}/test/validation/random/random_main$(EXEEXT) \
	${top_builddir}/test/validation/scheduler/scheduler_main$(EXEEXT) \
	${top_builddir}/test/validation/std_clib/std_clib_main$(EXEEXT) \
	${top_builddir}/test/validation/thread/thread_main$(EXEEXT) \
	${top_builddir}/test/validation/time/time_main$(EXEEXT) \
	${top_builddir}/test/validation/timer/timer_main$(EXEEXT) \
	${top_builddir}/test/validation/traffic_mngr/traffic_mngr_main$(EXEEXT) \
	${top_builddir}/test/validation/shmem/shmem_main$(EXEEXT) \
	${top_builddir}/test/validation/system/system_main$(EXEEXT)

SUBDIRS = $(ODP_MODULES)

if HAVE_PCAP
TESTS += pktio/pktio_run_pcap.sh
endif
if PKTIO_IPC
TESTS += pktio_ipc/pktio_ipc_run.sh
SUBDIRS += pktio_ipc
endif
if netmap_support
TESTS += pktio/pktio_run_netmap.sh
endif
if PKTIO_DPDK
TESTS += pktio/pktio_run_dpdk.sh
endif
endif

TEST_EXTENSIONS = .sh

dist_check_SCRIPTS = run-test tests-validation.env $(LOG_COMPILER)

test_SCRIPTS = $(dist_check_SCRIPTS)

tests-validation.env:
	echo "TESTS=\"$(TESTS)\""    > $@
	echo "$(TESTS_ENVIRONMENT)" >> $@
	echo "$(LOG_COMPILER)"      >> $@

if test_installdir
installcheck-local:
	$(DESTDIR)/$(testdir)/run-test
endif

#performance tests refer to pktio_env
if test_perf
SUBDIRS = pktio
endif
