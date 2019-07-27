#ifndef MACROS_H
#define MACROS_H
#include "externals.h"

#define file_rank_to_120sq(file, rank) ((file) + 21 + ((rank) * 10))
#define set_bit(bb, sq) ((bb) |= set_mask[(sq)])
#define clr_bit(bb, sq) ((bb) &= clr_mask[(sq)])
#define c_sq64(sq120) (sqs_64[(sq120)])
#define c_sq120(sq64) (sqs_120[(sq64)])

#endif