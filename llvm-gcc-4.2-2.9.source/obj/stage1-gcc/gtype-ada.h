/* Type information for ada.
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
gt_ggc_mx_lang_tree_node (void *x_p)
{
  union lang_tree_node * x = (union lang_tree_node *)x_p;
  union lang_tree_node * xlimit = x;
  while (ggc_test_and_set_mark (xlimit))
   xlimit = ((union lang_tree_node *)TREE_CHAIN (&(*xlimit).t));
  while (x != xlimit)
    {
      switch (0)
        {
        case 0:
          switch (tree_node_structure (&((*x).t)))
            {
            case TS_COMMON:
              gt_ggc_m_9tree_node ((*x).t.common.chain);
              gt_ggc_m_9tree_node ((*x).t.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.common.ann);
              break;
            case TS_INT_CST:
              gt_ggc_m_9tree_node ((*x).t.int_cst.common.chain);
              gt_ggc_m_9tree_node ((*x).t.int_cst.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.int_cst.common.ann);
              break;
            case TS_REAL_CST:
              gt_ggc_m_9tree_node ((*x).t.real_cst.common.chain);
              gt_ggc_m_9tree_node ((*x).t.real_cst.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.real_cst.common.ann);
              gt_ggc_m_10real_value ((*x).t.real_cst.real_cst_ptr);
              break;
            case TS_VECTOR:
              gt_ggc_m_9tree_node ((*x).t.vector.common.chain);
              gt_ggc_m_9tree_node ((*x).t.vector.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.vector.common.ann);
              gt_ggc_m_9tree_node ((*x).t.vector.elements);
              break;
            case TS_STRING:
              gt_ggc_m_9tree_node ((*x).t.string.common.chain);
              gt_ggc_m_9tree_node ((*x).t.string.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.string.common.ann);
              break;
            case TS_COMPLEX:
              gt_ggc_m_9tree_node ((*x).t.complex.common.chain);
              gt_ggc_m_9tree_node ((*x).t.complex.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.complex.common.ann);
              gt_ggc_m_9tree_node ((*x).t.complex.real);
              gt_ggc_m_9tree_node ((*x).t.complex.imag);
              break;
            case TS_IDENTIFIER:
              gt_ggc_m_9tree_node ((*x).t.identifier.common.chain);
              gt_ggc_m_9tree_node ((*x).t.identifier.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.identifier.common.ann);
              break;
            case TS_DECL_MINIMAL:
              gt_ggc_m_9tree_node ((*x).t.decl_minimal.common.chain);
              gt_ggc_m_9tree_node ((*x).t.decl_minimal.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.decl_minimal.common.ann);
              gt_ggc_m_9tree_node ((*x).t.decl_minimal.name);
              gt_ggc_m_9tree_node ((*x).t.decl_minimal.context);
              break;
            case TS_DECL_COMMON:
              gt_ggc_m_9tree_node ((*x).t.decl_common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.decl_common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.decl_common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.decl_common.common.name);
              gt_ggc_m_9tree_node ((*x).t.decl_common.common.context);
              gt_ggc_m_9tree_node ((*x).t.decl_common.size);
              gt_ggc_m_9tree_node ((*x).t.decl_common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.decl_common.initial);
              gt_ggc_m_9tree_node ((*x).t.decl_common.attributes);
              gt_ggc_m_9tree_node ((*x).t.decl_common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.decl_common.lang_specific);
              break;
            case TS_DECL_WRTL:
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.decl_with_rtl.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.size);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.initial);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.decl_with_rtl.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.decl_with_rtl.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.decl_with_rtl.rtl);
              break;
            case TS_DECL_NON_COMMON:
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.decl_non_common.common.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.decl_non_common.common.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.decl_non_common.common.common.rtl);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.assembler_name);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.common.section_name);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.saved_tree);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.arguments);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.result);
              gt_ggc_m_9tree_node ((*x).t.decl_non_common.vindex);
              break;
            case TS_PARM_DECL:
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.parm_decl.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.parm_decl.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.parm_decl.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.parm_decl.common.rtl);
              gt_ggc_m_7rtx_def ((*x).t.parm_decl.incoming_rtl);
              break;
            case TS_DECL_WITH_VIS:
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.decl_with_vis.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.decl_with_vis.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.decl_with_vis.common.rtl);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.assembler_name);
              gt_ggc_m_9tree_node ((*x).t.decl_with_vis.section_name);
              break;
            case TS_VAR_DECL:
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.var_decl.common.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.var_decl.common.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.var_decl.common.common.rtl);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.assembler_name);
              gt_ggc_m_9tree_node ((*x).t.var_decl.common.section_name);
              break;
            case TS_FIELD_DECL:
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.field_decl.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.size);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.initial);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.field_decl.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.field_decl.common.lang_specific);
              gt_ggc_m_9tree_node ((*x).t.field_decl.offset);
              gt_ggc_m_9tree_node ((*x).t.field_decl.bit_field_type);
              gt_ggc_m_9tree_node ((*x).t.field_decl.qualifier);
              gt_ggc_m_9tree_node ((*x).t.field_decl.bit_offset);
              gt_ggc_m_9tree_node ((*x).t.field_decl.fcontext);
              break;
            case TS_LABEL_DECL:
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.label_decl.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.label_decl.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.label_decl.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.label_decl.common.rtl);
              gt_ggc_m_9tree_node ((*x).t.label_decl.java_field_1);
              gt_ggc_m_9tree_node ((*x).t.label_decl.java_field_2);
              gt_ggc_m_9tree_node ((*x).t.label_decl.java_field_3);
              break;
            case TS_RESULT_DECL:
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.result_decl.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.result_decl.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.result_decl.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.result_decl.common.rtl);
              break;
            case TS_CONST_DECL:
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.const_decl.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.const_decl.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.const_decl.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.const_decl.common.rtl);
              break;
            case TS_TYPE_DECL:
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.type_decl.common.common.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.type_decl.common.common.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.type_decl.common.common.common.rtl);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.assembler_name);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.common.section_name);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.saved_tree);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.arguments);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.result);
              gt_ggc_m_9tree_node ((*x).t.type_decl.common.vindex);
              break;
            case TS_FUNCTION_DECL:
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.function_decl.common.common.common.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.size);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.size_unit);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.initial);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.attributes);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.common.common.abstract_origin);
              gt_ggc_m_9lang_decl ((*x).t.function_decl.common.common.common.common.lang_specific);
              gt_ggc_m_7rtx_def ((*x).t.function_decl.common.common.common.rtl);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.assembler_name);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.common.section_name);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.saved_tree);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.arguments);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.result);
              gt_ggc_m_9tree_node ((*x).t.function_decl.common.vindex);
              gt_ggc_m_8function ((*x).t.function_decl.f);
              break;
            case TS_TYPE:
              gt_ggc_m_9tree_node ((*x).t.type.common.chain);
              gt_ggc_m_9tree_node ((*x).t.type.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.type.common.ann);
              gt_ggc_m_9tree_node ((*x).t.type.values);
              gt_ggc_m_9tree_node ((*x).t.type.size);
              gt_ggc_m_9tree_node ((*x).t.type.size_unit);
              gt_ggc_m_9tree_node ((*x).t.type.attributes);
              gt_ggc_m_9tree_node ((*x).t.type.pointer_to);
              gt_ggc_m_9tree_node ((*x).t.type.reference_to);
              switch (LLVM_IS_ENABLED ? 3 : debug_hooks == &sdb_debug_hooks ? 1 : debug_hooks == &dwarf2_debug_hooks ? 2 : 0)
                {
                case 0:
                  break;
                case 1:
                  break;
                case 2:
                  gt_ggc_m_10die_struct ((*x).t.type.symtab.die);
                  break;
                case 3:
                  break;
                default:
                  break;
                }
              gt_ggc_m_9tree_node ((*x).t.type.name);
              gt_ggc_m_9tree_node ((*x).t.type.minval);
              gt_ggc_m_9tree_node ((*x).t.type.maxval);
              gt_ggc_m_9tree_node ((*x).t.type.next_variant);
              gt_ggc_m_9tree_node ((*x).t.type.main_variant);
              gt_ggc_m_9tree_node ((*x).t.type.binfo);
              gt_ggc_m_9tree_node ((*x).t.type.context);
              gt_ggc_m_9lang_type ((*x).t.type.lang_specific);
              break;
            case TS_LIST:
              gt_ggc_m_9tree_node ((*x).t.list.common.chain);
              gt_ggc_m_9tree_node ((*x).t.list.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.list.common.ann);
              gt_ggc_m_9tree_node ((*x).t.list.purpose);
              gt_ggc_m_9tree_node ((*x).t.list.value);
              break;
            case TS_VEC:
              gt_ggc_m_9tree_node ((*x).t.vec.common.chain);
              gt_ggc_m_9tree_node ((*x).t.vec.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.vec.common.ann);
              {
                size_t i1;
                for (i1 = 0; i1 != (size_t)(TREE_VEC_LENGTH ((tree)&((*x).t.vec))); i1++) {
                  gt_ggc_m_9tree_node ((*x).t.vec.a[i1]);
                }
              }
              break;
            case TS_EXP:
              gt_ggc_m_9tree_node ((*x).t.exp.common.chain);
              gt_ggc_m_9tree_node ((*x).t.exp.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.exp.common.ann);
              gt_ggc_m_10location_s ((*x).t.exp.locus);
              gt_ggc_m_9tree_node ((*x).t.exp.block);
              switch (TREE_CODE ((tree) &(*x)))
                {
                default:
                  {
                    size_t i2;
                    for (i2 = 0; i2 != (size_t)(TREE_CODE_LENGTH (TREE_CODE ((tree) &(*x)))); i2++) {
                      gt_ggc_m_9tree_node ((*x).t.exp.operands[i2]);
                    }
                  }
                  break;
                }
              break;
            case TS_SSA_NAME:
              gt_ggc_m_9tree_node ((*x).t.ssa_name.common.chain);
              gt_ggc_m_9tree_node ((*x).t.ssa_name.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.ssa_name.common.ann);
              gt_ggc_m_9tree_node ((*x).t.ssa_name.var);
              gt_ggc_m_12ptr_info_def ((*x).t.ssa_name.ptr_info);
              gt_ggc_m_9tree_node ((*x).t.ssa_name.value_handle);
              break;
            case TS_PHI_NODE:
              gt_ggc_m_9tree_node ((*x).t.phi.common.chain);
              gt_ggc_m_9tree_node ((*x).t.phi.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.phi.common.ann);
              gt_ggc_m_9tree_node ((*x).t.phi.result);
              gt_ggc_m_15basic_block_def ((*x).t.phi.bb);
              {
                size_t i3;
                for (i3 = 0; i3 != (size_t)(((tree)&((*x).t.phi))->phi.num_args); i3++) {
                  gt_ggc_m_9tree_node ((*x).t.phi.a[i3].def);
                }
              }
              break;
            case TS_BLOCK:
              gt_ggc_m_9tree_node ((*x).t.block.common.chain);
              gt_ggc_m_9tree_node ((*x).t.block.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.block.common.ann);
              gt_ggc_m_9tree_node ((*x).t.block.vars);
              gt_ggc_m_9tree_node ((*x).t.block.subblocks);
              gt_ggc_m_9tree_node ((*x).t.block.supercontext);
              gt_ggc_m_9tree_node ((*x).t.block.abstract_origin);
              gt_ggc_m_9tree_node ((*x).t.block.fragment_origin);
              gt_ggc_m_9tree_node ((*x).t.block.fragment_chain);
              break;
            case TS_BINFO:
              gt_ggc_m_9tree_node ((*x).t.binfo.common.chain);
              gt_ggc_m_9tree_node ((*x).t.binfo.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.binfo.common.ann);
              gt_ggc_m_9tree_node ((*x).t.binfo.offset);
              gt_ggc_m_9tree_node ((*x).t.binfo.vtable);
              gt_ggc_m_9tree_node ((*x).t.binfo.virtuals);
              gt_ggc_m_9tree_node ((*x).t.binfo.vptr_field);
              gt_ggc_m_11VEC_tree_gc ((*x).t.binfo.base_accesses);
              gt_ggc_m_9tree_node ((*x).t.binfo.inheritance);
              gt_ggc_m_9tree_node ((*x).t.binfo.vtt_subvtt);
              gt_ggc_m_9tree_node ((*x).t.binfo.vtt_vptr);
              {
                size_t i4;
                for (i4 = 0; i4 != (size_t)(((*x).t.binfo.base_binfos.base).num); i4++) {
                  gt_ggc_m_9tree_node ((*x).t.binfo.base_binfos.base.vec[i4]);
                }
              }
              break;
            case TS_STATEMENT_LIST:
              gt_ggc_m_9tree_node ((*x).t.stmt_list.common.chain);
              gt_ggc_m_9tree_node ((*x).t.stmt_list.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.stmt_list.common.ann);
              gt_ggc_m_24tree_statement_list_node ((*x).t.stmt_list.head);
              gt_ggc_m_24tree_statement_list_node ((*x).t.stmt_list.tail);
              break;
            case TS_VALUE_HANDLE:
              gt_ggc_m_9tree_node ((*x).t.value_handle.common.chain);
              gt_ggc_m_9tree_node ((*x).t.value_handle.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.value_handle.common.ann);
              gt_ggc_m_11VEC_tree_gc ((*x).t.value_handle.vuses);
              break;
            case TS_CONSTRUCTOR:
              gt_ggc_m_9tree_node ((*x).t.constructor.common.chain);
              gt_ggc_m_9tree_node ((*x).t.constructor.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.constructor.common.ann);
              gt_ggc_m_22VEC_constructor_elt_gc ((*x).t.constructor.elts);
              break;
            case TS_MEMORY_TAG:
              gt_ggc_m_9tree_node ((*x).t.mtag.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.mtag.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.mtag.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.mtag.common.name);
              gt_ggc_m_9tree_node ((*x).t.mtag.common.context);
              break;
            case TS_STRUCT_FIELD_TAG:
              gt_ggc_m_9tree_node ((*x).t.sft.common.common.common.chain);
              gt_ggc_m_9tree_node ((*x).t.sft.common.common.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.sft.common.common.common.ann);
              gt_ggc_m_9tree_node ((*x).t.sft.common.common.name);
              gt_ggc_m_9tree_node ((*x).t.sft.common.common.context);
              gt_ggc_m_9tree_node ((*x).t.sft.parent_var);
              break;
            case TS_OMP_CLAUSE:
              gt_ggc_m_9tree_node ((*x).t.omp_clause.common.chain);
              gt_ggc_m_9tree_node ((*x).t.omp_clause.common.type);
              gt_ggc_m_10tree_ann_d ((*x).t.omp_clause.common.ann);
              {
                size_t i5;
                for (i5 = 0; i5 != (size_t)(omp_clause_num_ops[OMP_CLAUSE_CODE ((tree)&((*x).t.omp_clause))]); i5++) {
                  gt_ggc_m_9tree_node ((*x).t.omp_clause.ops[i5]);
                }
              }
              break;
            default:
              break;
            }
          break;
        default:
          break;
        }
      x = ((union lang_tree_node *)TREE_CHAIN (&(*x).t));
    }
}

void
gt_ggc_mx_lang_decl (void *x_p)
{
  struct lang_decl * const x = (struct lang_decl *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).t);
    }
}

void
gt_ggc_mx_lang_type (void *x_p)
{
  struct lang_type * const x = (struct lang_type *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).t);
    }
}

void
gt_pch_nx_lang_tree_node (void *x_p)
{
  union lang_tree_node * x = (union lang_tree_node *)x_p;
  union lang_tree_node * xlimit = x;
  while (gt_pch_note_object (xlimit, xlimit, gt_pch_p_14lang_tree_node, gt_ggc_e_14lang_tree_node))
   xlimit = ((union lang_tree_node *)TREE_CHAIN (&(*xlimit).t));
  while (x != xlimit)
    {
      switch (0)
        {
        case 0:
          switch (tree_node_structure (&((*x).t)))
            {
            case TS_COMMON:
              gt_pch_n_9tree_node ((*x).t.common.chain);
              gt_pch_n_9tree_node ((*x).t.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.common.ann);
              break;
            case TS_INT_CST:
              gt_pch_n_9tree_node ((*x).t.int_cst.common.chain);
              gt_pch_n_9tree_node ((*x).t.int_cst.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.int_cst.common.ann);
              break;
            case TS_REAL_CST:
              gt_pch_n_9tree_node ((*x).t.real_cst.common.chain);
              gt_pch_n_9tree_node ((*x).t.real_cst.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.real_cst.common.ann);
              gt_pch_n_10real_value ((*x).t.real_cst.real_cst_ptr);
              break;
            case TS_VECTOR:
              gt_pch_n_9tree_node ((*x).t.vector.common.chain);
              gt_pch_n_9tree_node ((*x).t.vector.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.vector.common.ann);
              gt_pch_n_9tree_node ((*x).t.vector.elements);
              break;
            case TS_STRING:
              gt_pch_n_9tree_node ((*x).t.string.common.chain);
              gt_pch_n_9tree_node ((*x).t.string.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.string.common.ann);
              break;
            case TS_COMPLEX:
              gt_pch_n_9tree_node ((*x).t.complex.common.chain);
              gt_pch_n_9tree_node ((*x).t.complex.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.complex.common.ann);
              gt_pch_n_9tree_node ((*x).t.complex.real);
              gt_pch_n_9tree_node ((*x).t.complex.imag);
              break;
            case TS_IDENTIFIER:
              gt_pch_n_9tree_node ((*x).t.identifier.common.chain);
              gt_pch_n_9tree_node ((*x).t.identifier.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.identifier.common.ann);
              gt_pch_n_S ((*x).t.identifier.id.str);
              break;
            case TS_DECL_MINIMAL:
              gt_pch_n_9tree_node ((*x).t.decl_minimal.common.chain);
              gt_pch_n_9tree_node ((*x).t.decl_minimal.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.decl_minimal.common.ann);
              gt_pch_n_S ((*x).t.decl_minimal.locus.file);
              gt_pch_n_9tree_node ((*x).t.decl_minimal.name);
              gt_pch_n_9tree_node ((*x).t.decl_minimal.context);
              break;
            case TS_DECL_COMMON:
              gt_pch_n_9tree_node ((*x).t.decl_common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.decl_common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.decl_common.common.common.ann);
              gt_pch_n_S ((*x).t.decl_common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.decl_common.common.name);
              gt_pch_n_9tree_node ((*x).t.decl_common.common.context);
              gt_pch_n_9tree_node ((*x).t.decl_common.size);
              gt_pch_n_9tree_node ((*x).t.decl_common.size_unit);
              gt_pch_n_9tree_node ((*x).t.decl_common.initial);
              gt_pch_n_9tree_node ((*x).t.decl_common.attributes);
              gt_pch_n_9tree_node ((*x).t.decl_common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.decl_common.lang_specific);
              break;
            case TS_DECL_WRTL:
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.decl_with_rtl.common.common.common.ann);
              gt_pch_n_S ((*x).t.decl_with_rtl.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.common.name);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.common.context);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.size);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.initial);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.attributes);
              gt_pch_n_9tree_node ((*x).t.decl_with_rtl.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.decl_with_rtl.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.decl_with_rtl.rtl);
              break;
            case TS_DECL_NON_COMMON:
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.decl_non_common.common.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.decl_non_common.common.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.size);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.decl_non_common.common.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.decl_non_common.common.common.rtl);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.assembler_name);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.common.section_name);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.saved_tree);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.arguments);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.result);
              gt_pch_n_9tree_node ((*x).t.decl_non_common.vindex);
              break;
            case TS_PARM_DECL:
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.parm_decl.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.parm_decl.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.size);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.parm_decl.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.parm_decl.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.parm_decl.common.rtl);
              gt_pch_n_7rtx_def ((*x).t.parm_decl.incoming_rtl);
              break;
            case TS_DECL_WITH_VIS:
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.decl_with_vis.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.decl_with_vis.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.size);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.decl_with_vis.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.decl_with_vis.common.rtl);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.assembler_name);
              gt_pch_n_9tree_node ((*x).t.decl_with_vis.section_name);
              break;
            case TS_VAR_DECL:
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.var_decl.common.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.var_decl.common.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.size);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.var_decl.common.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.var_decl.common.common.rtl);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.assembler_name);
              gt_pch_n_9tree_node ((*x).t.var_decl.common.section_name);
              break;
            case TS_FIELD_DECL:
              gt_pch_n_9tree_node ((*x).t.field_decl.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.field_decl.common.common.common.ann);
              gt_pch_n_S ((*x).t.field_decl.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.common.name);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.common.context);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.size);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.initial);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.attributes);
              gt_pch_n_9tree_node ((*x).t.field_decl.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.field_decl.common.lang_specific);
              gt_pch_n_9tree_node ((*x).t.field_decl.offset);
              gt_pch_n_9tree_node ((*x).t.field_decl.bit_field_type);
              gt_pch_n_9tree_node ((*x).t.field_decl.qualifier);
              gt_pch_n_9tree_node ((*x).t.field_decl.bit_offset);
              gt_pch_n_9tree_node ((*x).t.field_decl.fcontext);
              break;
            case TS_LABEL_DECL:
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.label_decl.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.label_decl.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.size);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.label_decl.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.label_decl.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.label_decl.common.rtl);
              gt_pch_n_9tree_node ((*x).t.label_decl.java_field_1);
              gt_pch_n_9tree_node ((*x).t.label_decl.java_field_2);
              gt_pch_n_9tree_node ((*x).t.label_decl.java_field_3);
              break;
            case TS_RESULT_DECL:
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.result_decl.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.result_decl.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.size);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.result_decl.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.result_decl.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.result_decl.common.rtl);
              break;
            case TS_CONST_DECL:
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.const_decl.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.const_decl.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.size);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.const_decl.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.const_decl.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.const_decl.common.rtl);
              break;
            case TS_TYPE_DECL:
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.type_decl.common.common.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.type_decl.common.common.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.size);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.type_decl.common.common.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.type_decl.common.common.common.rtl);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.assembler_name);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.common.section_name);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.saved_tree);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.arguments);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.result);
              gt_pch_n_9tree_node ((*x).t.type_decl.common.vindex);
              break;
            case TS_FUNCTION_DECL:
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.function_decl.common.common.common.common.common.common.ann);
              gt_pch_n_S ((*x).t.function_decl.common.common.common.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.common.name);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.common.context);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.size);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.size_unit);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.initial);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.attributes);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.common.common.abstract_origin);
              gt_pch_n_9lang_decl ((*x).t.function_decl.common.common.common.common.lang_specific);
              gt_pch_n_7rtx_def ((*x).t.function_decl.common.common.common.rtl);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.assembler_name);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.common.section_name);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.saved_tree);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.arguments);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.result);
              gt_pch_n_9tree_node ((*x).t.function_decl.common.vindex);
              gt_pch_n_8function ((*x).t.function_decl.f);
              break;
            case TS_TYPE:
              gt_pch_n_9tree_node ((*x).t.type.common.chain);
              gt_pch_n_9tree_node ((*x).t.type.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.type.common.ann);
              gt_pch_n_9tree_node ((*x).t.type.values);
              gt_pch_n_9tree_node ((*x).t.type.size);
              gt_pch_n_9tree_node ((*x).t.type.size_unit);
              gt_pch_n_9tree_node ((*x).t.type.attributes);
              gt_pch_n_9tree_node ((*x).t.type.pointer_to);
              gt_pch_n_9tree_node ((*x).t.type.reference_to);
              switch (LLVM_IS_ENABLED ? 3 : debug_hooks == &sdb_debug_hooks ? 1 : debug_hooks == &dwarf2_debug_hooks ? 2 : 0)
                {
                case 0:
                  break;
                case 1:
                  gt_pch_n_S ((*x).t.type.symtab.pointer);
                  break;
                case 2:
                  gt_pch_n_10die_struct ((*x).t.type.symtab.die);
                  break;
                case 3:
                  break;
                default:
                  break;
                }
              gt_pch_n_9tree_node ((*x).t.type.name);
              gt_pch_n_9tree_node ((*x).t.type.minval);
              gt_pch_n_9tree_node ((*x).t.type.maxval);
              gt_pch_n_9tree_node ((*x).t.type.next_variant);
              gt_pch_n_9tree_node ((*x).t.type.main_variant);
              gt_pch_n_9tree_node ((*x).t.type.binfo);
              gt_pch_n_9tree_node ((*x).t.type.context);
              gt_pch_n_9lang_type ((*x).t.type.lang_specific);
              break;
            case TS_LIST:
              gt_pch_n_9tree_node ((*x).t.list.common.chain);
              gt_pch_n_9tree_node ((*x).t.list.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.list.common.ann);
              gt_pch_n_9tree_node ((*x).t.list.purpose);
              gt_pch_n_9tree_node ((*x).t.list.value);
              break;
            case TS_VEC:
              gt_pch_n_9tree_node ((*x).t.vec.common.chain);
              gt_pch_n_9tree_node ((*x).t.vec.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.vec.common.ann);
              {
                size_t i1;
                for (i1 = 0; i1 != (size_t)(TREE_VEC_LENGTH ((tree)&((*x).t.vec))); i1++) {
                  gt_pch_n_9tree_node ((*x).t.vec.a[i1]);
                }
              }
              break;
            case TS_EXP:
              gt_pch_n_9tree_node ((*x).t.exp.common.chain);
              gt_pch_n_9tree_node ((*x).t.exp.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.exp.common.ann);
              gt_pch_n_10location_s ((*x).t.exp.locus);
              gt_pch_n_9tree_node ((*x).t.exp.block);
              switch (TREE_CODE ((tree) &(*x)))
                {
                default:
                  {
                    size_t i2;
                    for (i2 = 0; i2 != (size_t)(TREE_CODE_LENGTH (TREE_CODE ((tree) &(*x)))); i2++) {
                      gt_pch_n_9tree_node ((*x).t.exp.operands[i2]);
                    }
                  }
                  break;
                }
              break;
            case TS_SSA_NAME:
              gt_pch_n_9tree_node ((*x).t.ssa_name.common.chain);
              gt_pch_n_9tree_node ((*x).t.ssa_name.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.ssa_name.common.ann);
              gt_pch_n_9tree_node ((*x).t.ssa_name.var);
              gt_pch_n_12ptr_info_def ((*x).t.ssa_name.ptr_info);
              gt_pch_n_9tree_node ((*x).t.ssa_name.value_handle);
              break;
            case TS_PHI_NODE:
              gt_pch_n_9tree_node ((*x).t.phi.common.chain);
              gt_pch_n_9tree_node ((*x).t.phi.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.phi.common.ann);
              gt_pch_n_9tree_node ((*x).t.phi.result);
              gt_pch_n_15basic_block_def ((*x).t.phi.bb);
              {
                size_t i3;
                for (i3 = 0; i3 != (size_t)(((tree)&((*x).t.phi))->phi.num_args); i3++) {
                  gt_pch_n_9tree_node ((*x).t.phi.a[i3].def);
                }
              }
              break;
            case TS_BLOCK:
              gt_pch_n_9tree_node ((*x).t.block.common.chain);
              gt_pch_n_9tree_node ((*x).t.block.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.block.common.ann);
              gt_pch_n_9tree_node ((*x).t.block.vars);
              gt_pch_n_9tree_node ((*x).t.block.subblocks);
              gt_pch_n_9tree_node ((*x).t.block.supercontext);
              gt_pch_n_9tree_node ((*x).t.block.abstract_origin);
              gt_pch_n_9tree_node ((*x).t.block.fragment_origin);
              gt_pch_n_9tree_node ((*x).t.block.fragment_chain);
              gt_pch_n_S ((*x).t.block.locus.file);
              break;
            case TS_BINFO:
              gt_pch_n_9tree_node ((*x).t.binfo.common.chain);
              gt_pch_n_9tree_node ((*x).t.binfo.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.binfo.common.ann);
              gt_pch_n_9tree_node ((*x).t.binfo.offset);
              gt_pch_n_9tree_node ((*x).t.binfo.vtable);
              gt_pch_n_9tree_node ((*x).t.binfo.virtuals);
              gt_pch_n_9tree_node ((*x).t.binfo.vptr_field);
              gt_pch_n_11VEC_tree_gc ((*x).t.binfo.base_accesses);
              gt_pch_n_9tree_node ((*x).t.binfo.inheritance);
              gt_pch_n_9tree_node ((*x).t.binfo.vtt_subvtt);
              gt_pch_n_9tree_node ((*x).t.binfo.vtt_vptr);
              {
                size_t i4;
                for (i4 = 0; i4 != (size_t)(((*x).t.binfo.base_binfos.base).num); i4++) {
                  gt_pch_n_9tree_node ((*x).t.binfo.base_binfos.base.vec[i4]);
                }
              }
              break;
            case TS_STATEMENT_LIST:
              gt_pch_n_9tree_node ((*x).t.stmt_list.common.chain);
              gt_pch_n_9tree_node ((*x).t.stmt_list.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.stmt_list.common.ann);
              gt_pch_n_24tree_statement_list_node ((*x).t.stmt_list.head);
              gt_pch_n_24tree_statement_list_node ((*x).t.stmt_list.tail);
              break;
            case TS_VALUE_HANDLE:
              gt_pch_n_9tree_node ((*x).t.value_handle.common.chain);
              gt_pch_n_9tree_node ((*x).t.value_handle.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.value_handle.common.ann);
              gt_pch_n_11VEC_tree_gc ((*x).t.value_handle.vuses);
              break;
            case TS_CONSTRUCTOR:
              gt_pch_n_9tree_node ((*x).t.constructor.common.chain);
              gt_pch_n_9tree_node ((*x).t.constructor.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.constructor.common.ann);
              gt_pch_n_22VEC_constructor_elt_gc ((*x).t.constructor.elts);
              break;
            case TS_MEMORY_TAG:
              gt_pch_n_9tree_node ((*x).t.mtag.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.mtag.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.mtag.common.common.ann);
              gt_pch_n_S ((*x).t.mtag.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.mtag.common.name);
              gt_pch_n_9tree_node ((*x).t.mtag.common.context);
              break;
            case TS_STRUCT_FIELD_TAG:
              gt_pch_n_9tree_node ((*x).t.sft.common.common.common.chain);
              gt_pch_n_9tree_node ((*x).t.sft.common.common.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.sft.common.common.common.ann);
              gt_pch_n_S ((*x).t.sft.common.common.locus.file);
              gt_pch_n_9tree_node ((*x).t.sft.common.common.name);
              gt_pch_n_9tree_node ((*x).t.sft.common.common.context);
              gt_pch_n_9tree_node ((*x).t.sft.parent_var);
              break;
            case TS_OMP_CLAUSE:
              gt_pch_n_9tree_node ((*x).t.omp_clause.common.chain);
              gt_pch_n_9tree_node ((*x).t.omp_clause.common.type);
              gt_pch_n_10tree_ann_d ((*x).t.omp_clause.common.ann);
              {
                size_t i5;
                for (i5 = 0; i5 != (size_t)(omp_clause_num_ops[OMP_CLAUSE_CODE ((tree)&((*x).t.omp_clause))]); i5++) {
                  gt_pch_n_9tree_node ((*x).t.omp_clause.ops[i5]);
                }
              }
              break;
            default:
              break;
            }
          break;
        default:
          break;
        }
      x = ((union lang_tree_node *)TREE_CHAIN (&(*x).t));
    }
}

void
gt_pch_nx_lang_decl (void *x_p)
{
  struct lang_decl * const x = (struct lang_decl *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_9lang_decl, gt_ggc_e_9lang_decl))
    {
      gt_pch_n_9tree_node ((*x).t);
    }
}

void
gt_pch_nx_lang_type (void *x_p)
{
  struct lang_type * const x = (struct lang_type *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_9lang_type, gt_ggc_e_9lang_type))
    {
      gt_pch_n_9tree_node ((*x).t);
    }
}

void
gt_pch_p_14lang_tree_node (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  union lang_tree_node * const x ATTRIBUTE_UNUSED = (union lang_tree_node *)x_p;
  switch (0)
    {
    case 0:
      switch (tree_node_structure (&((*x).t)))
        {
        case TS_COMMON:
          if ((void *)(x) == this_obj)
            op (&((*x).t.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.common.ann), cookie);
          break;
        case TS_INT_CST:
          if ((void *)(x) == this_obj)
            op (&((*x).t.int_cst.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.int_cst.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.int_cst.common.ann), cookie);
          break;
        case TS_REAL_CST:
          if ((void *)(x) == this_obj)
            op (&((*x).t.real_cst.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.real_cst.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.real_cst.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.real_cst.real_cst_ptr), cookie);
          break;
        case TS_VECTOR:
          if ((void *)(x) == this_obj)
            op (&((*x).t.vector.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.vector.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.vector.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.vector.elements), cookie);
          break;
        case TS_STRING:
          if ((void *)(x) == this_obj)
            op (&((*x).t.string.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.string.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.string.common.ann), cookie);
          break;
        case TS_COMPLEX:
          if ((void *)(x) == this_obj)
            op (&((*x).t.complex.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.complex.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.complex.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.complex.real), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.complex.imag), cookie);
          break;
        case TS_IDENTIFIER:
          if ((void *)(x) == this_obj)
            op (&((*x).t.identifier.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.identifier.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.identifier.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.identifier.id.str), cookie);
          break;
        case TS_DECL_MINIMAL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_minimal.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_minimal.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_minimal.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_minimal.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_minimal.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_minimal.context), cookie);
          break;
        case TS_DECL_COMMON:
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_common.lang_specific), cookie);
          break;
        case TS_DECL_WRTL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_rtl.rtl), cookie);
          break;
        case TS_DECL_NON_COMMON:
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.assembler_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.common.section_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.saved_tree), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.arguments), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.result), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_non_common.vindex), cookie);
          break;
        case TS_PARM_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.parm_decl.incoming_rtl), cookie);
          break;
        case TS_DECL_WITH_VIS:
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.assembler_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.decl_with_vis.section_name), cookie);
          break;
        case TS_VAR_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.assembler_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.var_decl.common.section_name), cookie);
          break;
        case TS_FIELD_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.offset), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.bit_field_type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.qualifier), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.bit_offset), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.field_decl.fcontext), cookie);
          break;
        case TS_LABEL_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.java_field_1), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.java_field_2), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.label_decl.java_field_3), cookie);
          break;
        case TS_RESULT_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.result_decl.common.rtl), cookie);
          break;
        case TS_CONST_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.const_decl.common.rtl), cookie);
          break;
        case TS_TYPE_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.assembler_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.common.section_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.saved_tree), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.arguments), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.result), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type_decl.common.vindex), cookie);
          break;
        case TS_FUNCTION_DECL:
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.initial), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.common.lang_specific), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.common.rtl), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.assembler_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.common.section_name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.saved_tree), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.arguments), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.result), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.common.vindex), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.function_decl.f), cookie);
          break;
        case TS_TYPE:
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.values), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.size), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.size_unit), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.attributes), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.pointer_to), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.reference_to), cookie);
          switch (LLVM_IS_ENABLED ? 3 : debug_hooks == &sdb_debug_hooks ? 1 : debug_hooks == &dwarf2_debug_hooks ? 2 : 0)
            {
            case 0:
              break;
            case 1:
              if ((void *)(x) == this_obj)
                op (&((*x).t.type.symtab.pointer), cookie);
              break;
            case 2:
              if ((void *)(x) == this_obj)
                op (&((*x).t.type.symtab.die), cookie);
              break;
            case 3:
              break;
            default:
              break;
            }
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.minval), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.maxval), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.next_variant), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.main_variant), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.binfo), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.type.lang_specific), cookie);
          break;
        case TS_LIST:
          if ((void *)(x) == this_obj)
            op (&((*x).t.list.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.list.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.list.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.list.purpose), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.list.value), cookie);
          break;
        case TS_VEC:
          if ((void *)(x) == this_obj)
            op (&((*x).t.vec.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.vec.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.vec.common.ann), cookie);
          {
            size_t i1;
            for (i1 = 0; i1 != (size_t)(TREE_VEC_LENGTH ((tree)&((*x).t.vec))); i1++) {
              if ((void *)(x) == this_obj)
                op (&((*x).t.vec.a[i1]), cookie);
            }
          }
          break;
        case TS_EXP:
          if ((void *)(x) == this_obj)
            op (&((*x).t.exp.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.exp.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.exp.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.exp.locus), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.exp.block), cookie);
          switch (TREE_CODE ((tree) &(*x)))
            {
            default:
              {
                size_t i2;
                for (i2 = 0; i2 != (size_t)(TREE_CODE_LENGTH (TREE_CODE ((tree) &(*x)))); i2++) {
                  if ((void *)(x) == this_obj)
                    op (&((*x).t.exp.operands[i2]), cookie);
                }
              }
              break;
            }
          break;
        case TS_SSA_NAME:
          if ((void *)(x) == this_obj)
            op (&((*x).t.ssa_name.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.ssa_name.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.ssa_name.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.ssa_name.var), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.ssa_name.ptr_info), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.ssa_name.value_handle), cookie);
          break;
        case TS_PHI_NODE:
          if ((void *)(x) == this_obj)
            op (&((*x).t.phi.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.phi.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.phi.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.phi.result), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.phi.bb), cookie);
          {
            size_t i3;
            for (i3 = 0; i3 != (size_t)(((tree)&((*x).t.phi))->phi.num_args); i3++) {
              if ((void *)(x) == this_obj)
                op (&((*x).t.phi.a[i3].def), cookie);
            }
          }
          break;
        case TS_BLOCK:
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.vars), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.subblocks), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.supercontext), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.abstract_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.fragment_origin), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.fragment_chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.block.locus.file), cookie);
          break;
        case TS_BINFO:
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.offset), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.vtable), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.virtuals), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.vptr_field), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.base_accesses), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.inheritance), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.vtt_subvtt), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.binfo.vtt_vptr), cookie);
          {
            size_t i4;
            for (i4 = 0; i4 != (size_t)(((*x).t.binfo.base_binfos.base).num); i4++) {
              if ((void *)(x) == this_obj)
                op (&((*x).t.binfo.base_binfos.base.vec[i4]), cookie);
            }
          }
          break;
        case TS_STATEMENT_LIST:
          if ((void *)(x) == this_obj)
            op (&((*x).t.stmt_list.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.stmt_list.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.stmt_list.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.stmt_list.head), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.stmt_list.tail), cookie);
          break;
        case TS_VALUE_HANDLE:
          if ((void *)(x) == this_obj)
            op (&((*x).t.value_handle.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.value_handle.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.value_handle.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.value_handle.vuses), cookie);
          break;
        case TS_CONSTRUCTOR:
          if ((void *)(x) == this_obj)
            op (&((*x).t.constructor.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.constructor.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.constructor.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.constructor.elts), cookie);
          break;
        case TS_MEMORY_TAG:
          if ((void *)(x) == this_obj)
            op (&((*x).t.mtag.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.mtag.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.mtag.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.mtag.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.mtag.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.mtag.common.context), cookie);
          break;
        case TS_STRUCT_FIELD_TAG:
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.common.common.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.common.common.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.common.common.common.ann), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.common.common.locus.file), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.common.common.name), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.common.common.context), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.sft.parent_var), cookie);
          break;
        case TS_OMP_CLAUSE:
          if ((void *)(x) == this_obj)
            op (&((*x).t.omp_clause.common.chain), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.omp_clause.common.type), cookie);
          if ((void *)(x) == this_obj)
            op (&((*x).t.omp_clause.common.ann), cookie);
          {
            size_t i5;
            for (i5 = 0; i5 != (size_t)(omp_clause_num_ops[OMP_CLAUSE_CODE ((tree)&((*x).t.omp_clause))]); i5++) {
              if ((void *)(x) == this_obj)
                op (&((*x).t.omp_clause.ops[i5]), cookie);
            }
          }
          break;
        default:
          break;
        }
      break;
    default:
      break;
    }
}

void
gt_pch_p_9lang_decl (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct lang_decl * const x ATTRIBUTE_UNUSED = (struct lang_decl *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).t), cookie);
}

void
gt_pch_p_9lang_type (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct lang_type * const x ATTRIBUTE_UNUSED = (struct lang_type *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).t), cookie);
}

/* GC roots.  */

const struct ggc_root_tab gt_ggc_r_gtype_ada_h[] = {
  {
    &static_dtors,
    1,
    sizeof (static_dtors),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &static_ctors,
    1,
    sizeof (static_ctors),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &gnat_raise_decls[0],
    1 * ((int) LAST_REASON_CODE + 1),
    sizeof (gnat_raise_decls[0]),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &gnat_std_decls[0],
    1 * ((int) ADT_LAST),
    sizeof (gnat_std_decls[0]),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  LAST_GGC_ROOT_TAB
};

extern const struct ggc_root_tab gt_ggc_r_gt_coverage_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_alias_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cselib_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cgraph_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ipa_inline_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dbxout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dwarf2out_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dwarf2asm_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_dojump_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_profile_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_except_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_explow_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_expr_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_function_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_gcse_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_optabs_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_regclass_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cfglayout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_sdbout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_stor_layout_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_stringpool_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_varasm_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_mudflap_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_ssanames_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_ssa_address_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_ssa_propagate_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_gimplify_h[];
extern const struct ggc_root_tab gt_ggc_r_gtype_desc_c[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_vect_generic_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_ssa_operands_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_tree_nested_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ipa_reference_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_omp_low_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_targhooks_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_cgraphunit_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_rs6000_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_darwin_h[];
extern const struct ggc_root_tab gt_ggc_r_gtype_ada_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ada_decl_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ada_trans_h[];
extern const struct ggc_root_tab gt_ggc_r_gt_ada_utils_h[];
const struct ggc_root_tab * const gt_ggc_rtab[] = {
  gt_ggc_r_gt_coverage_h,
  gt_ggc_r_gt_alias_h,
  gt_ggc_r_gt_cselib_h,
  gt_ggc_r_gt_cgraph_h,
  gt_ggc_r_gt_ipa_inline_h,
  gt_ggc_r_gt_dbxout_h,
  gt_ggc_r_gt_dwarf2out_h,
  gt_ggc_r_gt_dwarf2asm_h,
  gt_ggc_r_gt_dojump_h,
  gt_ggc_r_gt_tree_profile_h,
  gt_ggc_r_gt_emit_rtl_h,
  gt_ggc_r_gt_except_h,
  gt_ggc_r_gt_explow_h,
  gt_ggc_r_gt_expr_h,
  gt_ggc_r_gt_function_h,
  gt_ggc_r_gt_gcse_h,
  gt_ggc_r_gt_optabs_h,
  gt_ggc_r_gt_regclass_h,
  gt_ggc_r_gt_cfglayout_h,
  gt_ggc_r_gt_sdbout_h,
  gt_ggc_r_gt_stor_layout_h,
  gt_ggc_r_gt_stringpool_h,
  gt_ggc_r_gt_tree_h,
  gt_ggc_r_gt_varasm_h,
  gt_ggc_r_gt_tree_mudflap_h,
  gt_ggc_r_gt_tree_ssanames_h,
  gt_ggc_r_gt_tree_ssa_address_h,
  gt_ggc_r_gt_tree_ssa_propagate_h,
  gt_ggc_r_gt_gimplify_h,
  gt_ggc_r_gtype_desc_c,
  gt_ggc_r_gt_tree_vect_generic_h,
  gt_ggc_r_gt_tree_ssa_operands_h,
  gt_ggc_r_gt_tree_nested_h,
  gt_ggc_r_gt_ipa_reference_h,
  gt_ggc_r_gt_omp_low_h,
  gt_ggc_r_gt_targhooks_h,
  gt_ggc_r_gt_cgraphunit_h,
  gt_ggc_r_gt_rs6000_h,
  gt_ggc_r_gt_darwin_h,
  gt_ggc_r_gtype_ada_h,
  gt_ggc_r_gt_ada_decl_h,
  gt_ggc_r_gt_ada_trans_h,
  gt_ggc_r_gt_ada_utils_h,
  NULL
};
extern const struct ggc_root_tab gt_ggc_rd_gt_alias_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_bitmap_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_lists_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_tree_phinodes_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_tree_iterator_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_ada_trans_h[];
extern const struct ggc_root_tab gt_ggc_rd_gt_ada_utils_h[];
const struct ggc_root_tab * const gt_ggc_deletable_rtab[] = {
  gt_ggc_rd_gt_alias_h,
  gt_ggc_rd_gt_bitmap_h,
  gt_ggc_rd_gt_emit_rtl_h,
  gt_ggc_rd_gt_lists_h,
  gt_ggc_rd_gt_tree_phinodes_h,
  gt_ggc_rd_gt_tree_iterator_h,
  gt_ggc_rd_gt_ada_trans_h,
  gt_ggc_rd_gt_ada_utils_h,
  NULL
};
extern const struct ggc_cache_tab gt_ggc_rc_gt_emit_rtl_h[];
extern const struct ggc_cache_tab gt_ggc_rc_gt_tree_h[];
extern const struct ggc_cache_tab gt_ggc_rc_gt_tree_ssa_structalias_h[];
const struct ggc_cache_tab * const gt_ggc_cache_rtab[] = {
  gt_ggc_rc_gt_emit_rtl_h,
  gt_ggc_rc_gt_tree_h,
  gt_ggc_rc_gt_tree_ssa_structalias_h,
  NULL
};
extern const struct ggc_root_tab gt_pch_rc_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_pch_rc_gt_tree_h[];
extern const struct ggc_root_tab gt_pch_rc_gt_tree_ssa_structalias_h[];
const struct ggc_root_tab * const gt_pch_cache_rtab[] = {
  gt_pch_rc_gt_emit_rtl_h,
  gt_pch_rc_gt_tree_h,
  gt_pch_rc_gt_tree_ssa_structalias_h,
  NULL
};
extern const struct ggc_root_tab gt_pch_rs_gt_coverage_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_alias_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_dbxout_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_dwarf2out_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_dwarf2asm_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_emit_rtl_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_except_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_function_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_sdbout_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_tree_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_varasm_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_tree_ssa_address_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_gimplify_h[];
extern const struct ggc_root_tab gt_pch_rs_gtype_desc_c[];
extern const struct ggc_root_tab gt_pch_rs_gt_tree_vect_generic_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_omp_low_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_rs6000_h[];
extern const struct ggc_root_tab gt_pch_rs_gt_darwin_h[];
const struct ggc_root_tab * const gt_pch_scalar_rtab[] = {
  gt_pch_rs_gt_coverage_h,
  gt_pch_rs_gt_alias_h,
  gt_pch_rs_gt_dbxout_h,
  gt_pch_rs_gt_dwarf2out_h,
  gt_pch_rs_gt_dwarf2asm_h,
  gt_pch_rs_gt_emit_rtl_h,
  gt_pch_rs_gt_except_h,
  gt_pch_rs_gt_function_h,
  gt_pch_rs_gt_sdbout_h,
  gt_pch_rs_gt_tree_h,
  gt_pch_rs_gt_varasm_h,
  gt_pch_rs_gt_tree_ssa_address_h,
  gt_pch_rs_gt_gimplify_h,
  gt_pch_rs_gtype_desc_c,
  gt_pch_rs_gt_tree_vect_generic_h,
  gt_pch_rs_gt_omp_low_h,
  gt_pch_rs_gt_rs6000_h,
  gt_pch_rs_gt_darwin_h,
  NULL
};
