#ifndef DUMPTOOL_H
#define DUMPTOOL_H

#include <iostream>
#include <libproc.h>
#include <mach/mach_init.h>
#include <mach/vm_map.h>
#include <mach/vm_region.h>
#include <mach/mach.h>

//TODO FixUP Later
void dumpProcessMemory(pid_t pid, const char* filename)
{
//    char path[PROC_PIDPATHINFO_MAXSIZE];
//    if (proc_pidpath(pid, path, sizeof(path)) <= 0) {
//        printf("Failed to retrieve process path for pid %d\n", pid);
//        return;
//    }

//    FILE* file = fopen(filename, "w");
//    if (!file) {
//        printf("Failed to open file %s for writing\n", filename);
//        return;
//    }

//    vm_region_basic_info_data_64_t info;
//    mach_msg_type_number_t count = VM_REGION_BASIC_INFO_COUNT_64;
//    mach_port_t object_name = MACH_PORT_NULL;
//    mach_vm_address_t address = 0;
//    mach_vm_size_t size = 0;
//    mach_port_t task = MACH_PORT_NULL;

//    if (task_for_pid(mach_task_self(), pid, &task) != KERN_SUCCESS) {
//        printf("Failed to retrieve task port for pid %d\n", pid);
//        fclose(file);
//        return;
//    }

//    while (1) {
//        kern_return_t result = mach_vm_region(task, &address, &size, VM_REGION_BASIC_INFO_64, (vm_region_info_t)&info, &count, &object_name);
//        if (result != KERN_SUCCESS) {
//            printf("Failed to retrieve region info for process %s (pid %d)\n", path, pid);
//            break;
//        }

//        char* buffer = (char*)malloc(size);
//        if (!buffer) {
//            printf("Failed to allocate buffer for region of size %llu in process %s (pid %d)\n", size, path, pid);
//            break;
//        }

//        mach_vm_size_t bytes_copied = 0;
//        result = mach_vm_read_overwrite(task, address, size, (mach_vm_address_t)buffer, &bytes_copied);
//        if (result != KERN_SUCCESS) {
//            printf("Failed to read memory for region at address %llu (size %llu) in process %s (pid %d)\n", address, size, path, pid);
//            free(buffer);
//            break;
//        }

//        fwrite(buffer, bytes_copied, 1, file);

//        free(buffer);

//        if (size == 0) {
//            break;
//        }

//        address += size;
//    }

//    fclose(file);
}


#endif // DUMPTOOL_H
