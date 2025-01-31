/* Type information for dbxout.c.
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

void
gt_ggc_mx_qualified_typeinfo (void *x_p)
{
  struct qualified_typeinfo * const x = (struct qualified_typeinfo *)x_p;
  if (ggc_test_and_set_mark (x))
    {
    }
}

void
gt_ggc_mx_typeinfo (void *x_p)
{
  struct typeinfo * const x = (struct typeinfo *)x_p;
  if (ggc_test_and_set_mark (x))
    {
    }
}

void
gt_pch_nx_qualified_typeinfo (void *x_p)
{
  struct qualified_typeinfo * const x = (struct qualified_typeinfo *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_18qualified_typeinfo, gt_ggc_e_18qualified_typeinfo))
    {
    }
}

void
gt_pch_nx_typeinfo (void *x_p)
{
  struct typeinfo * const x = (struct typeinfo *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_8typeinfo, gt_ggc_e_8typeinfo))
    {
    }
}

void
gt_pch_p_18qualified_typeinfo (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct qualified_typeinfo * const x ATTRIBUTE_UNUSED = (struct qualified_typeinfo *)x_p;
}

void
gt_pch_p_8typeinfo (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct typeinfo * const x ATTRIBUTE_UNUSED = (struct typeinfo *)x_p;
}

/* GC roots.  */

static void gt_ggc_ma_type_queue (void *);
static void
gt_ggc_ma_type_queue (ATTRIBUTE_UNUSED void *x_p)
{
  if (type_queue != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(type_queue_index); i0++) {
      gt_ggc_m_9tree_node (type_queue[i0]);
    }
    ggc_mark (type_queue);
  }
}

static void gt_pch_pa_type_queue
    (void *, void *, gt_pointer_operator, void *);
static void gt_pch_pa_type_queue (ATTRIBUTE_UNUSED void *this_obj,
      ATTRIBUTE_UNUSED void *x_p,
      ATTRIBUTE_UNUSED gt_pointer_operator op,
      ATTRIBUTE_UNUSED void * cookie)
{
  if (type_queue != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(type_queue_index); i0++) {
      if ((void *)(type_queue) == this_obj)
        op (&(type_queue[i0]), cookie);
    }
    if ((void *)(&type_queue) == this_obj)
      op (&(type_queue), cookie);
  }
}

static void gt_pch_na_type_queue (void *);
static void
gt_pch_na_type_queue (ATTRIBUTE_UNUSED void *x_p)
{
  if (type_queue != NULL) {
    size_t i1;
    for (i1 = 0; i1 != (size_t)(type_queue_index); i1++) {
      gt_pch_n_9tree_node (type_queue[i1]);
    }
    gt_pch_note_object (type_queue, &type_queue, gt_pch_pa_type_queue, gt_types_enum_last);
  }
}

static void gt_ggc_ma_q_typevec (void *);
static void
gt_ggc_ma_q_typevec (ATTRIBUTE_UNUSED void *x_p)
{
  if (q_typevec != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(q_typevec_len); i0++) {
    }
    ggc_mark (q_typevec);
  }
}

static void gt_pch_pa_q_typevec
    (void *, void *, gt_pointer_operator, void *);
static void gt_pch_pa_q_typevec (ATTRIBUTE_UNUSED void *this_obj,
      ATTRIBUTE_UNUSED void *x_p,
      ATTRIBUTE_UNUSED gt_pointer_operator op,
      ATTRIBUTE_UNUSED void * cookie)
{
  if (q_typevec != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(q_typevec_len); i0++) {
    }
    if ((void *)(&q_typevec) == this_obj)
      op (&(q_typevec), cookie);
  }
}

static void gt_pch_na_q_typevec (void *);
static void
gt_pch_na_q_typevec (ATTRIBUTE_UNUSED void *x_p)
{
  if (q_typevec != NULL) {
    size_t i1;
    for (i1 = 0; i1 != (size_t)(q_typevec_len); i1++) {
    }
    gt_pch_note_object (q_typevec, &q_typevec, gt_pch_pa_q_typevec, gt_types_enum_last);
  }
}

static void gt_ggc_ma_typevec (void *);
static void
gt_ggc_ma_typevec (ATTRIBUTE_UNUSED void *x_p)
{
  if (typevec != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(typevec_len); i0++) {
    }
    ggc_mark (typevec);
  }
}

static void gt_pch_pa_typevec
    (void *, void *, gt_pointer_operator, void *);
static void gt_pch_pa_typevec (ATTRIBUTE_UNUSED void *this_obj,
      ATTRIBUTE_UNUSED void *x_p,
      ATTRIBUTE_UNUSED gt_pointer_operator op,
      ATTRIBUTE_UNUSED void * cookie)
{
  if (typevec != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(typevec_len); i0++) {
    }
    if ((void *)(&typevec) == this_obj)
      op (&(typevec), cookie);
  }
}

static void gt_pch_na_typevec (void *);
static void
gt_pch_na_typevec (ATTRIBUTE_UNUSED void *x_p)
{
  if (typevec != NULL) {
    size_t i1;
    for (i1 = 0; i1 != (size_t)(typevec_len); i1++) {
    }
    gt_pch_note_object (typevec, &typevec, gt_pch_pa_typevec, gt_types_enum_last);
  }
}

const struct ggc_root_tab gt_ggc_r_gt_dbxout_h[] = {
  {
    &type_queue,
    1,
    sizeof (type_queue),
    &gt_ggc_ma_type_queue,
    &gt_pch_na_type_queue
  },
  {
    &lastfile,
    1, 
    sizeof (lastfile),
    &gt_ggc_m_S,
    (gt_pointer_walker) &gt_pch_n_S
  },
  {
    &anon_place_holder,
    1,
    sizeof (anon_place_holder),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &preinit_symbols,
    1,
    sizeof (preinit_symbols),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &q_typevec,
    1,
    sizeof (q_typevec),
    &gt_ggc_ma_q_typevec,
    &gt_pch_na_q_typevec
  },
  {
    &typevec,
    1,
    sizeof (typevec),
    &gt_ggc_ma_typevec,
    &gt_pch_na_typevec
  },
  LAST_GGC_ROOT_TAB
};

const struct ggc_root_tab gt_pch_rs_gt_dbxout_h[] = {
  { &type_queue_size, 1, sizeof (type_queue_size), NULL, NULL },
  { &type_queue_index, 1, sizeof (type_queue_index), NULL, NULL },
  { &lastfile_is_base, 1, sizeof (lastfile_is_base), NULL, NULL },
  { &source_label_number, 1, sizeof (source_label_number), NULL, NULL },
  { &dbxout_source_line_counter, 1, sizeof (dbxout_source_line_counter), NULL, NULL },
  { &scope_labelno, 1, sizeof (scope_labelno), NULL, NULL },
  { &next_file_number, 1, sizeof (next_file_number), NULL, NULL },
  { &next_q_type_number, 1, sizeof (next_q_type_number), NULL, NULL },
  { &q_typevec_len, 1, sizeof (q_typevec_len), NULL, NULL },
  { &next_type_number, 1, sizeof (next_type_number), NULL, NULL },
  { &typevec_len, 1, sizeof (typevec_len), NULL, NULL },
  LAST_GGC_ROOT_TAB
};

