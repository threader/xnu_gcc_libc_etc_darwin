#ifndef	_host_priv_server_
#define	_host_priv_server_

/* Module host_priv */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry 	*function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	host_priv_MSG_COUNT
#define	host_priv_MSG_COUNT	25
#endif	/* host_priv_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <kern/ipc_kobject.h>
#include <kern/ipc_tt.h>
#include <kern/ipc_host.h>
#include <kern/ipc_sync.h>
#include <kern/ledger.h>
#include <kern/processor.h>
#include <kern/sync_lock.h>
#include <kern/sync_sema.h>
#include <vm/memory_object.h>
#include <vm/vm_map.h>
#include <kern/ipc_mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include <mach/mach_types.h>
#include <mach_debug/mach_debug_types.h>

#ifdef __BeforeMigServerHeader
__BeforeMigServerHeader
#endif /* __BeforeMigServerHeader */


/* Routine host_get_boot_info */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_get_boot_info
(
	host_priv_t host_priv,
	kernel_boot_info_t boot_info
);

/* Routine host_reboot */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_reboot
(
	host_priv_t host_priv,
	int options
);

/* Routine host_priv_statistics */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_priv_statistics
(
	host_priv_t host_priv,
	host_flavor_t flavor,
	host_info_t host_info_out,
	mach_msg_type_number_t *host_info_outCnt
);

/* Routine host_default_memory_manager */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_default_memory_manager
(
	host_priv_t host_priv,
	memory_object_default_t *default_manager,
	vm_size_t cluster_size
);

/* Routine vm_wire */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t vm_wire
(
	host_priv_t host_priv,
	vm_map_t task,
	vm_address_t address,
	vm_size_t size,
	vm_prot_t desired_access
);

/* Routine thread_wire */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t thread_wire
(
	host_priv_t host_priv,
	thread_act_t thread,
	boolean_t wired
);

/* Routine vm_allocate_cpm */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t vm_allocate_cpm
(
	host_priv_t host_priv,
	vm_map_t task,
	vm_address_t *address,
	vm_size_t size,
	boolean_t anywhere
);

/* Routine host_processors */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_processors
(
	host_priv_t host_priv,
	processor_array_t *out_processor_list,
	mach_msg_type_number_t *out_processor_listCnt
);

/* Routine host_get_clock_control */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_get_clock_control
(
	host_priv_t host_priv,
	clock_id_t clock_id,
	clock_ctrl_t *clock_ctrl
);

/* Routine kmod_create */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kmod_create
(
	host_priv_t host_priv,
	vm_address_t info,
	kmod_t *module
);

/* Routine kmod_destroy */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kmod_destroy
(
	host_priv_t host_priv,
	kmod_t module
);

/* Routine kmod_control */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t kmod_control
(
	host_priv_t host_priv,
	kmod_t module,
	kmod_control_flavor_t flavor,
	kmod_args_t *data,
	mach_msg_type_number_t *dataCnt
);

/* Routine host_get_special_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_get_special_port
(
	host_priv_t host_priv,
	int node,
	int which,
	mach_port_t *port
);

/* Routine host_set_special_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_set_special_port
(
	host_priv_t host_priv,
	int which,
	mach_port_t port
);

/* Routine host_set_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_set_exception_ports
(
	host_priv_t host_priv,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor
);

/* Routine host_get_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_get_exception_ports
(
	host_priv_t host_priv,
	exception_mask_t exception_mask,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlers,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine host_swap_exception_ports */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_swap_exception_ports
(
	host_priv_t host_priv,
	exception_mask_t exception_mask,
	mach_port_t new_port,
	exception_behavior_t behavior,
	thread_state_flavor_t new_flavor,
	exception_mask_array_t masks,
	mach_msg_type_number_t *masksCnt,
	exception_handler_array_t old_handlerss,
	exception_behavior_array_t old_behaviors,
	exception_flavor_array_t old_flavors
);

/* Routine host_load_symbol_table */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_load_symbol_table
(
	host_priv_t host,
	task_t task,
	symtab_name_t name,
	vm_offset_t symtab,
	mach_msg_type_number_t symtabCnt
);

/* Routine mach_vm_wire */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t mach_vm_wire
(
	host_priv_t host_priv,
	vm_map_t task,
	mach_vm_address_t address,
	mach_vm_size_t size,
	vm_prot_t desired_access
);

/* Routine host_processor_sets */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_processor_sets
(
	host_priv_t host_priv,
	processor_set_name_array_t *processor_sets,
	mach_msg_type_number_t *processor_setsCnt
);

/* Routine host_processor_set_priv */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_processor_set_priv
(
	host_priv_t host_priv,
	processor_set_name_t set_name,
	processor_set_t *set
);

/* Routine set_dp_control_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t set_dp_control_port
(
	host_priv_t host,
	mach_port_t control_port
);

/* Routine get_dp_control_port */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t get_dp_control_port
(
	host_priv_t host,
	mach_port_t *contorl_port
);

/* Routine host_set_UNDServer */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_set_UNDServer
(
	host_priv_t host,
	UNDServerRef server
);

/* Routine host_get_UNDServer */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t host_get_UNDServer
(
	host_priv_t host,
	UNDServerRef *server
);

extern boolean_t host_priv_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

extern mig_routine_t host_priv_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
extern const struct host_priv_subsystem {
	mig_server_routine_t	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[25];
} host_priv_subsystem;

/* typedefs for all requests */

#ifndef __Request__host_priv_subsystem__defined
#define __Request__host_priv_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__host_get_boot_info_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int options;
	} __Request__host_reboot_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		host_flavor_t flavor;
		mach_msg_type_number_t host_info_outCnt;
	} __Request__host_priv_statistics_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t default_manager;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		vm_size_t cluster_size;
	} __Request__host_default_memory_manager_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		vm_address_t address;
		vm_size_t size;
		vm_prot_t desired_access;
	} __Request__vm_wire_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t thread;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		boolean_t wired;
	} __Request__thread_wire_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		vm_address_t address;
		vm_size_t size;
		boolean_t anywhere;
	} __Request__vm_allocate_cpm_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__host_processors_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		clock_id_t clock_id;
	} __Request__host_get_clock_control_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		vm_address_t info;
	} __Request__kmod_create_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kmod_t module;
	} __Request__kmod_destroy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		kmod_t module;
		kmod_control_flavor_t flavor;
		mach_msg_type_number_t dataCnt;
	} __Request__kmod_control_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		int node;
		int which;
	} __Request__host_get_special_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		int which;
	} __Request__host_set_special_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
	} __Request__host_set_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		exception_mask_t exception_mask;
	} __Request__host_get_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t new_port;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		exception_mask_t exception_mask;
		exception_behavior_t behavior;
		thread_state_flavor_t new_flavor;
	} __Request__host_swap_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task;
		mach_msg_ool_descriptor_t symtab;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t nameOffset; /* MiG doesn't use it */
		mach_msg_type_number_t nameCnt;
		char name[32];
		mach_msg_type_number_t symtabCnt;
	} __Request__host_load_symbol_table_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t address;
		mach_vm_size_t size;
		vm_prot_t desired_access;
	} __Request__mach_vm_wire_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__host_processor_sets_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t set_name;
		/* end of the kernel processed data */
	} __Request__host_processor_set_priv_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t control_port;
		/* end of the kernel processed data */
	} __Request__set_dp_control_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__get_dp_control_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t server;
		/* end of the kernel processed data */
	} __Request__host_set_UNDServer_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__host_get_UNDServer_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Request__host_priv_subsystem__defined */


/* union of all requests */

#ifndef __RequestUnion__host_priv_subsystem__defined
#define __RequestUnion__host_priv_subsystem__defined
union __RequestUnion__host_priv_subsystem {
	__Request__host_get_boot_info_t Request_host_get_boot_info;
	__Request__host_reboot_t Request_host_reboot;
	__Request__host_priv_statistics_t Request_host_priv_statistics;
	__Request__host_default_memory_manager_t Request_host_default_memory_manager;
	__Request__vm_wire_t Request_vm_wire;
	__Request__thread_wire_t Request_thread_wire;
	__Request__vm_allocate_cpm_t Request_vm_allocate_cpm;
	__Request__host_processors_t Request_host_processors;
	__Request__host_get_clock_control_t Request_host_get_clock_control;
	__Request__kmod_create_t Request_kmod_create;
	__Request__kmod_destroy_t Request_kmod_destroy;
	__Request__kmod_control_t Request_kmod_control;
	__Request__host_get_special_port_t Request_host_get_special_port;
	__Request__host_set_special_port_t Request_host_set_special_port;
	__Request__host_set_exception_ports_t Request_host_set_exception_ports;
	__Request__host_get_exception_ports_t Request_host_get_exception_ports;
	__Request__host_swap_exception_ports_t Request_host_swap_exception_ports;
	__Request__host_load_symbol_table_t Request_host_load_symbol_table;
	__Request__mach_vm_wire_t Request_mach_vm_wire;
	__Request__host_processor_sets_t Request_host_processor_sets;
	__Request__host_processor_set_priv_t Request_host_processor_set_priv;
	__Request__set_dp_control_port_t Request_set_dp_control_port;
	__Request__get_dp_control_port_t Request_get_dp_control_port;
	__Request__host_set_UNDServer_t Request_host_set_UNDServer;
	__Request__host_get_UNDServer_t Request_host_get_UNDServer;
};
#endif /* __RequestUnion__host_priv_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__host_priv_subsystem__defined
#define __Reply__host_priv_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_msg_type_number_t boot_infoOffset; /* MiG doesn't use it */
		mach_msg_type_number_t boot_infoCnt;
		char boot_info[4096];
	} __Reply__host_get_boot_info_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__host_reboot_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_msg_type_number_t host_info_outCnt;
		integer_t host_info_out[14];
	} __Reply__host_priv_statistics_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t default_manager;
		/* end of the kernel processed data */
	} __Reply__host_default_memory_manager_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__vm_wire_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__thread_wire_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		vm_address_t address;
	} __Reply__vm_allocate_cpm_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t out_processor_list;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t out_processor_listCnt;
	} __Reply__host_processors_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t clock_ctrl;
		/* end of the kernel processed data */
	} __Reply__host_get_clock_control_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		kmod_t module;
	} __Reply__kmod_create_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__kmod_destroy_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_descriptor_t data;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t dataCnt;
	} __Reply__kmod_control_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t port;
		/* end of the kernel processed data */
	} __Reply__host_get_special_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__host_set_special_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__host_set_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t old_handlers[32];
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__host_get_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t old_handlerss[32];
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t masksCnt;
		exception_mask_t masks[32];
		exception_behavior_t old_behaviors[32];
		thread_state_flavor_t old_flavors[32];
	} __Reply__host_swap_exception_ports_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__host_load_symbol_table_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__mach_vm_wire_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_ool_ports_descriptor_t processor_sets;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_msg_type_number_t processor_setsCnt;
	} __Reply__host_processor_sets_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t set;
		/* end of the kernel processed data */
	} __Reply__host_processor_set_priv_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__set_dp_control_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t contorl_port;
		/* end of the kernel processed data */
	} __Reply__get_dp_control_port_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__host_set_UNDServer_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif

#ifdef  __MigPackStructs
#pragma pack(4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t server;
		/* end of the kernel processed data */
	} __Reply__host_get_UNDServer_t;
#ifdef  __MigPackStructs
#pragma pack()
#endif
#endif /* !__Reply__host_priv_subsystem__defined */


/* union of all replies */

#ifndef __ReplyUnion__host_priv_subsystem__defined
#define __ReplyUnion__host_priv_subsystem__defined
union __ReplyUnion__host_priv_subsystem {
	__Reply__host_get_boot_info_t Reply_host_get_boot_info;
	__Reply__host_reboot_t Reply_host_reboot;
	__Reply__host_priv_statistics_t Reply_host_priv_statistics;
	__Reply__host_default_memory_manager_t Reply_host_default_memory_manager;
	__Reply__vm_wire_t Reply_vm_wire;
	__Reply__thread_wire_t Reply_thread_wire;
	__Reply__vm_allocate_cpm_t Reply_vm_allocate_cpm;
	__Reply__host_processors_t Reply_host_processors;
	__Reply__host_get_clock_control_t Reply_host_get_clock_control;
	__Reply__kmod_create_t Reply_kmod_create;
	__Reply__kmod_destroy_t Reply_kmod_destroy;
	__Reply__kmod_control_t Reply_kmod_control;
	__Reply__host_get_special_port_t Reply_host_get_special_port;
	__Reply__host_set_special_port_t Reply_host_set_special_port;
	__Reply__host_set_exception_ports_t Reply_host_set_exception_ports;
	__Reply__host_get_exception_ports_t Reply_host_get_exception_ports;
	__Reply__host_swap_exception_ports_t Reply_host_swap_exception_ports;
	__Reply__host_load_symbol_table_t Reply_host_load_symbol_table;
	__Reply__mach_vm_wire_t Reply_mach_vm_wire;
	__Reply__host_processor_sets_t Reply_host_processor_sets;
	__Reply__host_processor_set_priv_t Reply_host_processor_set_priv;
	__Reply__set_dp_control_port_t Reply_set_dp_control_port;
	__Reply__get_dp_control_port_t Reply_get_dp_control_port;
	__Reply__host_set_UNDServer_t Reply_host_set_UNDServer;
	__Reply__host_get_UNDServer_t Reply_host_get_UNDServer;
};
#endif /* __RequestUnion__host_priv_subsystem__defined */

#ifndef subsystem_to_name_map_host_priv
#define subsystem_to_name_map_host_priv \
    { "host_get_boot_info", 400 },\
    { "host_reboot", 401 },\
    { "host_priv_statistics", 402 },\
    { "host_default_memory_manager", 403 },\
    { "vm_wire", 404 },\
    { "thread_wire", 405 },\
    { "vm_allocate_cpm", 406 },\
    { "host_processors", 407 },\
    { "host_get_clock_control", 408 },\
    { "kmod_create", 409 },\
    { "kmod_destroy", 410 },\
    { "kmod_control", 411 },\
    { "host_get_special_port", 412 },\
    { "host_set_special_port", 413 },\
    { "host_set_exception_ports", 414 },\
    { "host_get_exception_ports", 415 },\
    { "host_swap_exception_ports", 416 },\
    { "host_load_symbol_table", 417 },\
    { "mach_vm_wire", 418 },\
    { "host_processor_sets", 419 },\
    { "host_processor_set_priv", 420 },\
    { "set_dp_control_port", 421 },\
    { "get_dp_control_port", 422 },\
    { "host_set_UNDServer", 423 },\
    { "host_get_UNDServer", 424 }
#endif

#ifdef __AfterMigServerHeader
__AfterMigServerHeader
#endif /* __AfterMigServerHeader */

#endif	 /* _host_priv_server_ */
