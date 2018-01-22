/* WARNING: THIS FILE IS AUTOMATICALLY GENERATED FROM A .SM FILE.
 * Changes made here will certainly be overwritten.
 */

/* 
 * (C) 2001 Clemson University and The University of Chicago 
 *
 * See COPYING in top-level directory.
 */

#include <string.h>
#include <assert.h>

#include "server-config.h"
#include "pvfs2-storage.h"
#include "pvfs2-server.h"
#include "pint-util.h"
//#include "pvfs2-attr.h"
#include "gossip.h"
#include "pvfs2-internal.h"
#include "dist-dir-utils.h"

static struct PINT_state_s ST_prelude;
static struct PINT_pjmp_tbl_s ST_prelude_pjtbl[];
static struct PINT_tran_tbl_s ST_prelude_trtbl[];

static PINT_sm_action mgmt_get_dirent_get_dist_dir_attr(
	struct PINT_smcb *smcb, job_status_s *js_p);

static struct PINT_state_s ST_get_dist_dir_attr;
static struct PINT_pjmp_tbl_s ST_get_dist_dir_attr_pjtbl[];
static struct PINT_tran_tbl_s ST_get_dist_dir_attr_trtbl[];

static PINT_sm_action mgmt_get_dirent_get_bitmap(
	struct PINT_smcb *smcb, job_status_s *js_p);

static struct PINT_state_s ST_get_bitmap;
static struct PINT_pjmp_tbl_s ST_get_bitmap_pjtbl[];
static struct PINT_tran_tbl_s ST_get_bitmap_trtbl[];

static PINT_sm_action mgmt_get_dirent(
	struct PINT_smcb *smcb, job_status_s *js_p);

static struct PINT_state_s ST_get_dirent;
static struct PINT_pjmp_tbl_s ST_get_dirent_pjtbl[];
static struct PINT_tran_tbl_s ST_get_dirent_trtbl[];

static PINT_sm_action mgmt_get_dirent_setup_resp(
	struct PINT_smcb *smcb, job_status_s *js_p);

static struct PINT_state_s ST_get_dirent_setup_resp;
static struct PINT_pjmp_tbl_s ST_get_dirent_setup_resp_pjtbl[];
static struct PINT_tran_tbl_s ST_get_dirent_setup_resp_trtbl[];
static struct PINT_state_s ST_final_response;
static struct PINT_pjmp_tbl_s ST_final_response_pjtbl[];
static struct PINT_tran_tbl_s ST_final_response_trtbl[];

static PINT_sm_action mgmt_get_dirent_cleanup(
	struct PINT_smcb *smcb, job_status_s *js_p);

static struct PINT_state_s ST_cleanup;
static struct PINT_pjmp_tbl_s ST_cleanup_pjtbl[];
static struct PINT_tran_tbl_s ST_cleanup_trtbl[];

struct PINT_state_machine_s pvfs2_mgmt_get_dirent_sm = {
	.name = "pvfs2_mgmt_get_dirent_sm",
	.first_state = &ST_prelude
};

static struct PINT_state_s ST_prelude = {
	 .state_name = "prelude" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_JUMP ,
	 .action.nested = &pvfs2_prelude_sm ,
	 .pjtbl = NULL ,
	 .trtbl = ST_prelude_trtbl 
};

static struct PINT_tran_tbl_s ST_prelude_trtbl[] = {
	{ .return_value = 0 ,
	 .next_state = &ST_get_dist_dir_attr },
	{ .return_value = -1 ,
	 .next_state = &ST_final_response }
};

static struct PINT_state_s ST_get_dist_dir_attr = {
	 .state_name = "get_dist_dir_attr" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_RUN ,
	 .action.func = mgmt_get_dirent_get_dist_dir_attr ,
	 .pjtbl = NULL ,
	 .trtbl = ST_get_dist_dir_attr_trtbl 
};

static struct PINT_tran_tbl_s ST_get_dist_dir_attr_trtbl[] = {
	{ .return_value = 0 ,
	 .next_state = &ST_get_bitmap },
	{ .return_value = -1 ,
	 .next_state = &ST_get_dirent_setup_resp }
};

static struct PINT_state_s ST_get_bitmap = {
	 .state_name = "get_bitmap" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_RUN ,
	 .action.func = mgmt_get_dirent_get_bitmap ,
	 .pjtbl = NULL ,
	 .trtbl = ST_get_bitmap_trtbl 
};

static struct PINT_tran_tbl_s ST_get_bitmap_trtbl[] = {
	{ .return_value = 0 ,
	 .next_state = &ST_get_dirent },
	{ .return_value = -1 ,
	 .next_state = &ST_get_dirent_setup_resp }
};

static struct PINT_state_s ST_get_dirent = {
	 .state_name = "get_dirent" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_RUN ,
	 .action.func = mgmt_get_dirent ,
	 .pjtbl = NULL ,
	 .trtbl = ST_get_dirent_trtbl 
};

static struct PINT_tran_tbl_s ST_get_dirent_trtbl[] = {
	{ .return_value = -1 ,
	 .next_state = &ST_get_dirent_setup_resp }
};

static struct PINT_state_s ST_get_dirent_setup_resp = {
	 .state_name = "get_dirent_setup_resp" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_RUN ,
	 .action.func = mgmt_get_dirent_setup_resp ,
	 .pjtbl = NULL ,
	 .trtbl = ST_get_dirent_setup_resp_trtbl 
};

static struct PINT_tran_tbl_s ST_get_dirent_setup_resp_trtbl[] = {
	{ .return_value = -1 ,
	 .next_state = &ST_final_response }
};

static struct PINT_state_s ST_final_response = {
	 .state_name = "final_response" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_JUMP ,
	 .action.nested = &pvfs2_final_response_sm ,
	 .pjtbl = NULL ,
	 .trtbl = ST_final_response_trtbl 
};

static struct PINT_tran_tbl_s ST_final_response_trtbl[] = {
	{ .return_value = -1 ,
	 .next_state = &ST_cleanup }
};

static struct PINT_state_s ST_cleanup = {
	 .state_name = "cleanup" ,
	 .parent_machine = &pvfs2_mgmt_get_dirent_sm ,
	 .flag = SM_RUN ,
	 .action.func = mgmt_get_dirent_cleanup ,
	 .pjtbl = NULL ,
	 .trtbl = ST_cleanup_trtbl 
};

static struct PINT_tran_tbl_s ST_cleanup_trtbl[] = {
	{ .return_value = -1 ,

	 .flag = SM_TERM }
};

#ifndef WIN32
# 71 "src/server/mgmt-get-dirent.sm"
#endif


static PINT_sm_action mgmt_get_dirent_get_dist_dir_attr(
        struct PINT_smcb *smcb, job_status_s *js_p)
{
    struct PINT_server_op *s_op = PINT_sm_frame(smcb, PINT_FRAME_CURRENT);
    int ret;
    job_id_t j_id;

    /* set up key and value structures for reading the dist_dir_attr */
    s_op->key.buffer = Trove_Common_Keys[DIST_DIR_ATTR_KEY].key;
    s_op->key.buffer_sz = Trove_Common_Keys[DIST_DIR_ATTR_KEY].size;
    if(s_op->free_val)
    {
        free(s_op->val.buffer);
    }

    s_op->val.buffer = &s_op->attr.dist_dir_attr;
    s_op->val.buffer_sz = sizeof(PVFS_dist_dir_attr);
    s_op->free_val = 0;

    js_p->error_code = 0;
    gossip_debug(GOSSIP_SERVER_DEBUG,
		 "  trying to read dist_dir_attr (coll_id = %d, "
                 "handle = %llu, key = %s (%d), val_buf = %p (%d))\n",
		 s_op->req->u.mgmt_get_dirent.fs_id, llu(s_op->req->u.mgmt_get_dirent.handle),
		 (char *)s_op->key.buffer, s_op->key.buffer_sz,
		 s_op->val.buffer, s_op->val.buffer_sz);

    ret = job_trove_keyval_read(
        s_op->req->u.mgmt_get_dirent.fs_id, s_op->req->u.mgmt_get_dirent.handle,
        &s_op->key, &s_op->val,
        0,
        NULL, smcb, 0, js_p,
        &j_id, server_job_context, s_op->req->hints);

    return ret;
}


static PINT_sm_action mgmt_get_dirent_get_bitmap(
        struct PINT_smcb *smcb, job_status_s *js_p)
{
    struct PINT_server_op *s_op = PINT_sm_frame(smcb, PINT_FRAME_CURRENT);
    int ret;
    PVFS_object_attr *attr_p;
    job_id_t j_id;

    attr_p = &s_op->attr;

    if(js_p->error_code == -TROVE_ENOENT)
    {
        gossip_debug(GOSSIP_SERVER_DEBUG, "mgmt_get_dirent: no DIST_DIR_ATTR key present in dirdata handle!!\n");
        attr_p->dist_dir_bitmap = NULL;
        attr_p->dirdata_handles = NULL;
        return SM_ACTION_COMPLETE;
    }

    assert(attr_p->dist_dir_attr.num_servers > 0);
    
    gossip_debug(GOSSIP_SERVER_DEBUG, 
            "mgmt_get_dirent: get dist-dir-attr for dirdata handle %llu "
            "with tree_height=%d, num_servers=%d, bitmap_size=%d, "
            "split_size=%d, server_no=%d and branch_level=%d\n",
            llu(s_op->req->u.mgmt_get_dirent.handle),
            attr_p->dist_dir_attr.tree_height,
            attr_p->dist_dir_attr.num_servers,
            attr_p->dist_dir_attr.bitmap_size,
            attr_p->dist_dir_attr.split_size,
            attr_p->dist_dir_attr.server_no,
            attr_p->dist_dir_attr.branch_level);

    /* allocate space for dirdata bitmap */
    attr_p->dirdata_handles = NULL; 
    attr_p->dist_dir_bitmap =
        malloc(attr_p->dist_dir_attr.bitmap_size *
                sizeof(PVFS_dist_dir_bitmap_basetype));
    if(!attr_p->dist_dir_bitmap)
    {
        js_p->error_code = -PVFS_ENOMEM;
        return SM_ACTION_COMPLETE;
    }

    /* set up attr->mask */
    attr_p->mask |= PVFS_ATTR_DISTDIR_ATTR;

    /* set up key and value structures for reading dirdata bitmap */
    s_op->key.buffer = Trove_Common_Keys[DIST_DIRDATA_BITMAP_KEY].key;
    s_op->key.buffer_sz = Trove_Common_Keys[DIST_DIRDATA_BITMAP_KEY].size;
    if(s_op->free_val)
    {
        free(s_op->val.buffer);
    }

    s_op->val.buffer = attr_p->dist_dir_bitmap;
    s_op->val.buffer_sz = 
        attr_p->dist_dir_attr.bitmap_size *
        sizeof(PVFS_dist_dir_bitmap_basetype);
    s_op->free_val = 0; /* will be freed in PINT_free_object_attr*/

    js_p->error_code = 0;
    gossip_debug(GOSSIP_SERVER_DEBUG,
		 "  trying to read dirdata bitmap (coll_id = %d, "
                 "handle = %llu, key = %s (%d), val_buf = %p (%d))\n",
		 s_op->req->u.mgmt_get_dirent.fs_id, llu(s_op->req->u.mgmt_get_dirent.handle),
		 (char *)s_op->key.buffer, s_op->key.buffer_sz,
		 s_op->val.buffer, s_op->val.buffer_sz);

    ret = job_trove_keyval_read(
        s_op->req->u.mgmt_get_dirent.fs_id, s_op->req->u.mgmt_get_dirent.handle,
        &s_op->key, &s_op->val,
        0,
        NULL, smcb, 0, js_p,
        &j_id, server_job_context, s_op->req->hints);

    return ret;
}

static int mgmt_get_dirent(
        struct PINT_smcb *smcb, job_status_s *js_p)
{
    struct PINT_server_op *s_op = PINT_sm_frame(smcb, PINT_FRAME_CURRENT);
    int ret = -PVFS_EINVAL;
    job_id_t j_id;
    int i;
    unsigned char *c;
    PVFS_object_attr *attr_p;

    js_p->error_code = 0;

    attr_p = &s_op->attr;

    /* gossip bitmap, since jump from get_bitmap*/
    gossip_debug(GOSSIP_SERVER_DEBUG,
            "mgmt_get_dirent: dist_dir_bitmap as:\n");
    for(i = attr_p->dist_dir_attr.bitmap_size - 1;
            i >= 0 ; i--)
    {
        c = (unsigned char *)(attr_p->dist_dir_bitmap + i);
        gossip_debug(GOSSIP_SERVER_DEBUG,
                " i=%d : %02x %02x %02x %02x\n",
                i, c[3], c[2], c[1], c[0]);
    }
    gossip_debug(GOSSIP_SERVER_DEBUG, "\n");


    /* make sure the entry belongs to the dirdata handle*/
    PVFS_dist_dir_hash_type dirdata_hash;
    int dirdata_server_index;

    /* find the hash value and the dist dir bucket */
    dirdata_hash = PINT_encrypt_dirdata(s_op->req->u.mgmt_get_dirent.entry);
    gossip_debug(GOSSIP_SERVER_DEBUG, "mgmt_get_dirent: encrypt dirent %s into hash value %llu.\n",
            s_op->req->u.mgmt_get_dirent.entry,
            llu(dirdata_hash));

    dirdata_server_index = 
        PINT_find_dist_dir_bucket(dirdata_hash,
            &attr_p->dist_dir_attr,
            attr_p->dist_dir_bitmap);
    gossip_debug(GOSSIP_SERVER_DEBUG, "mgmt_get_dirent: selecting bucket No.%d from dist_dir_bitmap.\n",
            dirdata_server_index);

    if(dirdata_server_index != 
            attr_p->dist_dir_attr.server_no)
    {
        gossip_debug(GOSSIP_SERVER_DEBUG, 
                "mgmt_get_dirent: error: WRONG dirdata object for the dirent! Returning error.\n");

        /* return an error to tell the client to try again */
        js_p->error_code = -PVFS_EAGAIN;
        return SM_ACTION_COMPLETE;
    }
    else
    {
        gossip_debug(GOSSIP_SERVER_DEBUG, 
                "mgmt_get_dirent: Correct dirdata object!\n");
    }


    s_op->key.buffer = s_op->req->u.mgmt_get_dirent.entry;
    s_op->key.buffer_sz = strlen(s_op->req->u.mgmt_get_dirent.entry) + 1;

    s_op->val.buffer = &s_op->u.mgmt_get_dirent.handle;
    s_op->val.buffer_sz = sizeof(PVFS_handle);

    gossip_debug(
        GOSSIP_SERVER_DEBUG,
        "  reading dirent handle (coll_id = %d, handle = %llu\n\t"
        "key = %s (%d), val_buf = %p (%d))\n",
        s_op->req->u.mgmt_get_dirent.fs_id,
        llu(s_op->req->u.mgmt_get_dirent.handle),
        (char *)s_op->key.buffer, s_op->key.buffer_sz,
        s_op->val.buffer, s_op->val.buffer_sz);

    ret = job_trove_keyval_read(
        s_op->req->u.mgmt_get_dirent.fs_id,
        s_op->req->u.mgmt_get_dirent.handle,
        &s_op->key, &s_op->val, 
        TROVE_KEYVAL_DIRECTORY_ENTRY, 
        NULL, smcb, 0, js_p, &j_id,
        server_job_context, s_op->req->hints);

    return ret;
}

static PINT_sm_action mgmt_get_dirent_setup_resp(
        struct PINT_smcb *smcb, job_status_s *js_p)
{
    struct PINT_server_op *s_op = PINT_sm_frame(smcb, PINT_FRAME_CURRENT);

    s_op->resp.u.mgmt_get_dirent.error = js_p->error_code;
    if (js_p->error_code == 0)
    {
        s_op->resp.u.mgmt_get_dirent.handle =
            s_op->u.mgmt_get_dirent.handle;

        gossip_debug(
            GOSSIP_SERVER_DEBUG, "  Found dirent handle %llu\n",
            llu(s_op->u.mgmt_get_dirent.handle));
    }
    else
    {
        s_op->resp.u.mgmt_get_dirent.handle = PVFS_HANDLE_NULL;
        s_op->resp.u.mgmt_get_dirent.error = js_p->error_code;
        js_p->error_code = 0;

        gossip_debug(GOSSIP_SERVER_DEBUG, "Failed to retrieve dirent handle\n");
    }
    return SM_ACTION_COMPLETE;
}

static PINT_sm_action mgmt_get_dirent_cleanup(
        struct PINT_smcb *smcb, job_status_s *js_p)
{
    struct PINT_server_op *s_op = PINT_sm_frame(smcb, PINT_FRAME_CURRENT);

    PINT_free_object_attr(&s_op->attr);
    return(server_state_machine_complete(smcb));
}

static int perm_mgmt_get_dirent(PINT_server_op *s_op)
{
    int ret;

    ret = 0;

    return ret;
}

PINT_GET_OBJECT_REF_DEFINE(mgmt_get_dirent);

struct PINT_server_req_params pvfs2_mgmt_get_dirent_params =
{
    .string_name = "mgmt-get-dirent",
    .get_object_ref = PINT_get_object_ref_mgmt_get_dirent,
    .perm = perm_mgmt_get_dirent,
    .sched_policy = PINT_SERVER_REQ_SCHEDULE,
    .access_type = PINT_server_req_readonly,
    .state_machine = &pvfs2_mgmt_get_dirent_sm
};

/*
 * Local variables:
 *  mode: c
 *  c-indent-level: 4
 *  c-basic-offset: 4
 * End:
 *
 * vim: ft=c ts=8 sts=4 sw=4 expandtab
 */