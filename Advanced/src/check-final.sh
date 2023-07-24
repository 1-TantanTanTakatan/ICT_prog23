#!/bin/bash
set -e
# use-ld=lld -fsanitize=cfi -fsanitize-address-use-after-return=always gc-sections->dead_strip  icf=all
# -target=arm64-apple-darwin21.3.0
# detect_leaks
clang -Wall -Wextra -Wtautological-compare -Wsign-compare -O1 -flto=full -gfull -fstandalone-debug  -ftrivial-auto-var-init=pattern -pipe -fintegrated-as -fintegrated-cc1 -ffunction-sections -fdata-sections -Wl,-dead_strip -Wl,-pie -fstack-protector-all -fno-sanitize-recover=all -fvisibility=hidden -fsanitize=undefined -fsanitize=integer -fsanitize=address -fsanitize-address-use-after-scope -fsanitize-address-use-odr-indicator -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-common -U_FORTIFY_SOURCE -fPIE  "$1" hugeint.c -lm
echo 'ここまではコンパイラからの警告・エラーメッセージです'
echo 'この後はプログラムを実行した時のエラーです'
shift
UBSAN_OPTIONS="print_stacktrace=1:abort_on_error=1" ASAN_OPTIONS="strict_init_order=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_string_checks=1:detect_invalid_pointer_pairs=2:use_odr_indicator=1:abort_on_error=1" exec ./a.out "$@"
