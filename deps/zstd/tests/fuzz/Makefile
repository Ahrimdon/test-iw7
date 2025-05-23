# ################################################################
# Copyright (c) Meta Platforms, Inc. and affiliates.
# All rights reserved.
#
# This source code is licensed under both the BSD-style license (found in the
# LICENSE file in the root directory of this source tree) and the GPLv2 (found
# in the COPYING file in the root directory of this source tree).
# You may select, at your option, one of the above-listed licenses.
# ################################################################

# Optionally user defined flags
CFLAGS ?= -O3
CXXFLAGS ?= -O3
CPPFLAGS ?=
ASFLAGS ?=
LDFLAGS ?=
ARFLAGS ?=
LIB_FUZZING_ENGINE ?= libregression.a
PYTHON ?= python
ifeq ($(shell uname), Darwin)
	DOWNLOAD?=curl -L -o
else
	DOWNLOAD?=wget -O
endif
CORPORA_URL_PREFIX:=https://github.com/facebook/zstd/releases/download/fuzz-corpora/

LIBZSTD_MK_DIR = ../../lib
DEBUGLEVEL ?= 2
ZSTD_LEGACY_SUPPORT ?= 1

include $(LIBZSTD_MK_DIR)/libzstd.mk

PRGDIR = ../../programs
CONTRIBDIR = ../../contrib

DEFAULT_SEQ_PROD_DIR = $(CONTRIBDIR)/externalSequenceProducer
DEFAULT_SEQ_PROD_SRC = $(DEFAULT_SEQ_PROD_DIR)/sequence_producer.c
THIRD_PARTY_SEQ_PROD_OBJ ?=

FUZZ_CPPFLAGS := -I$(LIB_SRCDIR) -I$(LIB_SRCDIR)/common -I$(LIB_SRCDIR)/compress \
	-I$(LIB_SRCDIR)/dictBuilder -I$(LIB_SRCDIR)/deprecated -I$(LIB_SRCDIR)/legacy \
	-I$(CONTRIBDIR)/seekable_format -I$(PRGDIR) -I$(DEFAULT_SEQ_PROD_DIR) \
	-DZSTD_MULTITHREAD -DZSTD_LEGACY_SUPPORT=1 $(CPPFLAGS)
FUZZ_EXTRA_FLAGS := -Wall -Wextra -Wcast-qual -Wcast-align -Wshadow \
	-Wstrict-aliasing=1 -Wswitch-enum -Wdeclaration-after-statement \
	-Wstrict-prototypes -Wundef \
	-Wvla -Wformat=2 -Winit-self -Wfloat-equal -Wwrite-strings \
	-Wredundant-decls -Wno-deprecated-declarations \
	-g -fno-omit-frame-pointer
FUZZ_CFLAGS := $(FUZZ_EXTRA_FLAGS) $(CFLAGS)
FUZZ_ASFLAGS := $(FUZZ_EXTRA_FLAGS) $(ASFLAGS)
FUZZ_CXXFLAGS := $(FUZZ_EXTRA_FLAGS) -std=c++11 $(CXXFLAGS)
FUZZ_LDFLAGS := -pthread $(LDFLAGS)
FUZZ_ARFLAGS := $(ARFLAGS)
FUZZ_TARGET_FLAGS = $(FUZZ_CPPFLAGS) $(FUZZ_CXXFLAGS) $(FUZZ_LDFLAGS)

FUZZ_ROUND_TRIP_FLAGS := -DFUZZING_ASSERT_VALID_SEQUENCE

FUZZ_HEADERS := fuzz_helpers.h fuzz.h zstd_helpers.h fuzz_data_producer.h
FUZZ_SRC := $(PRGDIR)/util.c ./fuzz_helpers.c ./zstd_helpers.c ./fuzz_data_producer.c

SEEKABLE_HEADERS = $(CONTRIBDIR)/seekable_format/zstd_seekable.h
SEEKABLE_OBJS = $(CONTRIBDIR)/seekable_format/zstdseek_compress.c $(CONTRIBDIR)/seekable_format/zstdseek_decompress.c

ZSTDCOMMON_SRC := $(ZSTD_COMMON_FILES)
ZSTDCOMP_SRC   := $(ZSTD_COMPRESS_FILES)
ZSTDDECOMP_SRC := $(ZSTD_DECOMPRESS_FILES)
ZSTDDICT_SRC := $(ZSTD_DICTBUILDER_FILES)
ZSTDLEGACY_SRC := $(ZSTD_LEGACY_FILES)
FUZZ_SRC       := \
	$(FUZZ_SRC) \
	$(ZSTDDECOMP_SRC) \
	$(ZSTDCOMMON_SRC) \
	$(ZSTDCOMP_SRC) \
	$(ZSTDDICT_SRC) \
	$(ZSTDLEGACY_SRC) \
	$(DEFAULT_SEQ_PROD_SRC)
FUZZ_SRC := $(sort $(wildcard $(FUZZ_SRC)))

FUZZ_D_OBJ1 := $(subst $(LIB_SRCDIR)/common/,d_lib_common_,$(FUZZ_SRC))
FUZZ_D_OBJ2 := $(subst $(LIB_SRCDIR)/compress/,d_lib_compress_,$(FUZZ_D_OBJ1))
FUZZ_D_OBJ3 := $(subst $(LIB_SRCDIR)/decompress/,d_lib_decompress_,$(FUZZ_D_OBJ2))
FUZZ_D_OBJ4 := $(subst $(LIB_SRCDIR)/dictBuilder/,d_lib_dictBuilder_,$(FUZZ_D_OBJ3))
FUZZ_D_OBJ5 := $(subst $(LIB_SRCDIR)/legacy/,d_lib_legacy_,$(FUZZ_D_OBJ4))
FUZZ_D_OBJ6 := $(subst $(PRGDIR)/,d_prg_,$(FUZZ_D_OBJ5))
FUZZ_D_OBJ7 := $(subst $(DEFAULT_SEQ_PROD_DIR)/,d_default_seq_prod_,$(FUZZ_D_OBJ6))
FUZZ_D_OBJ8 := $(subst $\./,d_fuzz_,$(FUZZ_D_OBJ7))
FUZZ_D_OBJ9 := $(FUZZ_D_OBJ8:.c=.o)
FUZZ_D_OBJ10 := $(THIRD_PARTY_SEQ_PROD_OBJ) $(FUZZ_D_OBJ9)
FUZZ_DECOMPRESS_OBJ := $(FUZZ_D_OBJ10:.S=.o)

FUZZ_RT_OBJ1 := $(subst $(LIB_SRCDIR)/common/,rt_lib_common_,$(FUZZ_SRC))
FUZZ_RT_OBJ2 := $(subst $(LIB_SRCDIR)/compress/,rt_lib_compress_,$(FUZZ_RT_OBJ1))
FUZZ_RT_OBJ3 := $(subst $(LIB_SRCDIR)/decompress/,rt_lib_decompress_,$(FUZZ_RT_OBJ2))
FUZZ_RT_OBJ4 := $(subst $(LIB_SRCDIR)/dictBuilder/,rt_lib_dictBuilder_,$(FUZZ_RT_OBJ3))
FUZZ_RT_OBJ5 := $(subst $(LIB_SRCDIR)/legacy/,rt_lib_legacy_,$(FUZZ_RT_OBJ4))
FUZZ_RT_OBJ6 := $(subst $(PRGDIR)/,rt_prg_,$(FUZZ_RT_OBJ5))
FUZZ_RT_OBJ7 := $(subst $(DEFAULT_SEQ_PROD_DIR)/,rt_default_seq_prod_,$(FUZZ_RT_OBJ6))
FUZZ_RT_OBJ8 := $(subst $\./,rt_fuzz_,$(FUZZ_RT_OBJ7))
FUZZ_RT_OBJ9 := $(FUZZ_RT_OBJ8:.c=.o)
FUZZ_RT_OBJ10 := $(THIRD_PARTY_SEQ_PROD_OBJ) $(FUZZ_RT_OBJ9)
FUZZ_ROUND_TRIP_OBJ := $(FUZZ_RT_OBJ10:.S=.o)

.PHONY: default all clean cleanall

default: all

FUZZ_TARGETS :=       \
	simple_round_trip \
	stream_round_trip \
	block_round_trip  \
	simple_decompress \
	stream_decompress \
	block_decompress  \
	dictionary_round_trip \
	dictionary_decompress \
	zstd_frame_info \
	simple_compress \
	dictionary_loader \
	raw_dictionary_round_trip \
	dictionary_stream_round_trip \
	decompress_dstSize_tooSmall \
	fse_read_ncount \
	sequence_compression_api \
	seekable_roundtrip \
	huf_round_trip \
	huf_decompress

all: libregression.a $(FUZZ_TARGETS)

rt_lib_common_%.o: $(LIB_SRCDIR)/common/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_lib_compress_%.o: $(LIB_SRCDIR)/compress/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_lib_decompress_%.o: $(LIB_SRCDIR)/decompress/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_lib_decompress_%.o: $(LIB_SRCDIR)/decompress/%.S
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_ASFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_lib_dictBuilder_%.o: $(LIB_SRCDIR)/dictBuilder/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_lib_legacy_%.o: $(LIB_SRCDIR)/legacy/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_prg_%.o: $(PRGDIR)/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_fuzz_%.o: %.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

rt_default_seq_prod_%.o: $(DEFAULT_SEQ_PROD_DIR)/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $(FUZZ_ROUND_TRIP_FLAGS) $< -c -o $@

d_lib_common_%.o: $(LIB_SRCDIR)/common/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_lib_compress_%.o: $(LIB_SRCDIR)/compress/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_lib_decompress_%.o: $(LIB_SRCDIR)/decompress/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_lib_decompress_%.o: $(LIB_SRCDIR)/decompress/%.S
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_ASFLAGS) $< -c -o $@

d_lib_dictBuilder_%.o: $(LIB_SRCDIR)/dictBuilder/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_lib_legacy_%.o: $(LIB_SRCDIR)/legacy/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_prg_%.o: $(PRGDIR)/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_fuzz_%.o: %.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

d_default_seq_prod_%.o: $(DEFAULT_SEQ_PROD_DIR)/%.c
	$(CC) $(FUZZ_CPPFLAGS) $(FUZZ_CFLAGS) $< -c -o $@

simple_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_simple_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_simple_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

stream_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_stream_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_stream_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

block_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_block_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_block_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

simple_decompress: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_simple_decompress.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_simple_decompress.o $(LIB_FUZZING_ENGINE) -o $@

stream_decompress: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_stream_decompress.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_stream_decompress.o $(LIB_FUZZING_ENGINE) -o $@

block_decompress: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_block_decompress.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_block_decompress.o $(LIB_FUZZING_ENGINE) -o $@

dictionary_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_dictionary_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_dictionary_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

raw_dictionary_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_raw_dictionary_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_raw_dictionary_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

dictionary_stream_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_dictionary_stream_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_dictionary_stream_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

dictionary_decompress: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_dictionary_decompress.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_dictionary_decompress.o $(LIB_FUZZING_ENGINE) -o $@

simple_compress: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_simple_compress.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_simple_compress.o $(LIB_FUZZING_ENGINE) -o $@

zstd_frame_info: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_zstd_frame_info.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_zstd_frame_info.o $(LIB_FUZZING_ENGINE) -o $@

dictionary_loader: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_dictionary_loader.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_dictionary_loader.o $(LIB_FUZZING_ENGINE) -o $@

decompress_dstSize_tooSmall: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_decompress_dstSize_tooSmall.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_decompress_dstSize_tooSmall.o $(LIB_FUZZING_ENGINE) -o $@

fse_read_ncount: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_fse_read_ncount.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_fse_read_ncount.o $(LIB_FUZZING_ENGINE) -o $@

sequence_compression_api: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_sequence_compression_api.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_sequence_compression_api.o $(LIB_FUZZING_ENGINE) -o $@

seekable_roundtrip: $(FUZZ_HEADERS) $(SEEKABLE_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) $(SEEKABLE_OBJS)  rt_fuzz_seekable_roundtrip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) $(SEEKABLE_OBJS) rt_fuzz_seekable_roundtrip.o $(LIB_FUZZING_ENGINE) -o $@

huf_round_trip: $(FUZZ_HEADERS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_huf_round_trip.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_ROUND_TRIP_OBJ) rt_fuzz_huf_round_trip.o $(LIB_FUZZING_ENGINE) -o $@

huf_decompress: $(FUZZ_HEADERS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_huf_decompress.o
	$(CXX) $(FUZZ_TARGET_FLAGS) $(FUZZ_DECOMPRESS_OBJ) d_fuzz_huf_decompress.o $(LIB_FUZZING_ENGINE) -o $@

libregression.a: $(FUZZ_HEADERS) $(PRGDIR)/util.h $(PRGDIR)/util.c d_fuzz_regression_driver.o
	$(AR) $(FUZZ_ARFLAGS) $@ d_fuzz_regression_driver.o

corpora/%_seed_corpus.zip:
	@mkdir -p corpora
	$(DOWNLOAD) $@ $(CORPORA_URL_PREFIX)$*_seed_corpus.zip

corpora/%: corpora/%_seed_corpus.zip
	unzip -q $^ -d $@

.PHONY: corpora
corpora: $(patsubst %,corpora/%,$(FUZZ_TARGETS))

.PHONY: seedcorpora
seedcorpora: $(patsubst %,corpora/%_seed_corpus.zip,$(FUZZ_TARGETS))

regressiontest: corpora
	CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)" CXXFLAGS="$(CXXFLAGS)" LDFLAGS="$(LDFLAGS)" $(PYTHON) ./fuzz.py build all --debug=$(DEBUGLEVEL)
	$(PYTHON) ./fuzz.py regression all

clean:
	@$(RM) *.a *.o $(FUZZ_TARGETS)
	@echo Cleaning completed

cleanall:
	@$(RM) -r Fuzzer
	@$(RM) -r corpora
	@echo Cleaning completed
