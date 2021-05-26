#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"

#define MAX 16

int
main(void)
{
  struct uproc *proc = malloc(sizeof(struct uproc)*MAX);
  int proc_num = getprocs(MAX, proc);
  printf(1,"PID\tName\t\tUID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n");

  int i;
  for(i = 0; i<proc_num; i++){
    struct uproc current_proc = proc[i];
    uint elapsed_ticks = current_proc.elapsed_ticks;
    uint elapsed_s = elapsed_ticks/1000;
    uint elapsed_ms = elapsed_ticks%1000;

    uint elapsed_cpu_ticks = current_proc.CPU_total_ticks;
    uint elapsed_cpu_s = elapsed_cpu_ticks/1000;
    uint elapsed_cpu_ms = elapsed_cpu_ticks % 1000;

    char* zero = "";
    if(elapsed_ms < 100 && elapsed_ms >= 10)
      zero = "0";
    if(elapsed_ms < 10)
      zero = "00";

    char* cpu_zero = "";
    if(elapsed_cpu_ms < 100 && elapsed_cpu_ms >= 10)
      cpu_zero = "0";
    if(elapsed_cpu_ms < 10)
      cpu_zero = "00";

    printf(
      1,
      "%d\t%s\t\t%d\t%d\t%d\t%d.%s%d\t%d.%s%d\t%s\t%d\n",
      current_proc.pid,
      current_proc.name,
      current_proc.uid,
      current_proc.gid,
      current_proc.ppid,
      elapsed_s, zero, elapsed_ms,
      elapsed_cpu_s, cpu_zero, elapsed_cpu_ms,
      current_proc.state,
      current_proc.size
    );
  }

  free(proc);
  exit();
}
#endif