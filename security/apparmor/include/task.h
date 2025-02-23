/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * AppArmor security module
 *
 * This file contains AppArmor task related definitions and mediation
 *
 * Copyright 2017 Canonical Ltd.
 */

#ifndef __AA_TASK_H
#define __AA_TASK_H

static inline struct aa_task_ctx *task_ctx(struct task_struct *task)
{
	return task->security + apparmor_blob_sizes.lbs_task;
}

/*
 * struct aa_task_ctx - information for current task label change
 * @nnp: snapshot of label at time of no_new_privs
 * @onexec: profile to transition to on next exec  (MAY BE NULL)
 * @previous: profile the task may return to     (MAY BE NULL)
 * @token: magic value the task must know for returning to @previous_profile
 */
struct aa_task_ctx {
	struct aa_label *nnp;
	struct aa_label *onexec;
	struct aa_label *previous;
	u64 token;
};

int aa_replace_current_label(struct aa_label *label);
void aa_set_current_onexec(struct aa_label *label, bool stack);
int aa_set_current_hat(struct aa_label *label, u64 token);
int aa_restore_previous_label(u64 cookie);
struct aa_label *aa_get_task_label(struct task_struct *task);

/**
 * aa_free_task_ctx - free a task_ctx
 * @ctx: task_ctx to free (MAYBE NULL)
 */
static inline void aa_free_task_ctx(struct aa_task_ctx *ctx)
{
	if (ctx) {
		aa_put_label(ctx->nnp);
		aa_put_label(ctx->previous);
		aa_put_label(ctx->onexec);
	}
}

/**
 * aa_dup_task_ctx - duplicate a task context, incrementing reference counts
 * @new: a blank task context      (NOT NULL)
 * @old: the task context to copy  (NOT NULL)
 */
static inline void aa_dup_task_ctx(struct aa_task_ctx *new,
				   const struct aa_task_ctx *old)
{
	*new = *old;
	aa_get_label(new->nnp);
	aa_get_label(new->previous);
	aa_get_label(new->onexec);
}

/**
 * aa_clear_task_ctx_trans - clear transition tracking info from the ctx
 * @ctx: task context to clear (NOT NULL)
 */
static inline void aa_clear_task_ctx_trans(struct aa_task_ctx *ctx)
{
	AA_BUG(!ctx);

	aa_put_label(ctx->previous);
	aa_put_label(ctx->onexec);
	ctx->previous = NULL;
	ctx->onexec = NULL;
	ctx->token = 0;
}

#define AA_PTRACE_TRACE		MAY_WRITE
#define AA_PTRACE_READ		MAY_READ
#define AA_MAY_BE_TRACED	AA_MAY_APPEND
#define AA_MAY_BE_READ		AA_MAY_CREATE
#define PTRACE_PERM_SHIFT	2

#define AA_PTRACE_PERM_MASK (AA_PTRACE_READ | AA_PTRACE_TRACE | \
			     AA_MAY_BE_READ | AA_MAY_BE_TRACED)
#define AA_SIGNAL_PERM_MASK (MAY_READ | MAY_WRITE)

#define AA_SFS_SIG_MASK "hup int quit ill trap abrt bus fpe kill usr1 " \
	"segv usr2 pipe alrm term stkflt chld cont stop stp ttin ttou urg " \
	"xcpu xfsz vtalrm prof winch io pwr sys emt lost"

int aa_may_ptrace(const struct cred *tracer_cred, struct aa_label *tracer,
		  const struct cred *tracee_cred, struct aa_label *tracee,
		  u32 request);



#define AA_USERNS_CREATE	8

struct aa_label *aa_profile_ns_perm(struct aa_profile *profile,
				    struct apparmor_audit_data *ad,
				    u32 request);

#endif /* __AA_TASK_H */
