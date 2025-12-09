#include "args.h"
#include "utils.h"
#include "preprocess.h"

/* Single definitions for globals declared as extern in headers */
struct arguments args;
char *current_target = NULL;
char include_stack[MAXINCLUDES][1024];
