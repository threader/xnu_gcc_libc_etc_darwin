/* Type information for coverage.c.
   Copyright (C) 2004 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

/* This file is machine generated.  Do not edit.  */

/* GC roots.  */

const struct ggc_root_tab gt_ggc_r_gt_coverage_h[] = {
  {
    &ctr_labels[0],
    1 * (GCOV_COUNTERS),
    sizeof (ctr_labels[0]),
    &gt_ggc_mx_rtx_def,
    &gt_pch_nx_rtx_def
  },
  {
    &tree_ctr_tables[0],
    1 * (GCOV_COUNTERS),
    sizeof (tree_ctr_tables[0]),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  LAST_GGC_ROOT_TAB
};

const struct ggc_root_tab gt_pch_rs_gt_coverage_h[] = {
  { &fn_b_ctrs, 1, sizeof (fn_b_ctrs), NULL, NULL },
  { &fn_n_ctrs, 1, sizeof (fn_n_ctrs), NULL, NULL },
  { &fn_ctr_mask, 1, sizeof (fn_ctr_mask), NULL, NULL },
  { &prg_n_ctrs, 1, sizeof (prg_n_ctrs), NULL, NULL },
  { &prg_ctr_mask, 1, sizeof (prg_ctr_mask), NULL, NULL },
  LAST_GGC_ROOT_TAB
};

