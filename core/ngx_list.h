#ifndef _NGX_LIST_H_INCLUDED_
#define _NGX_LIST_H_INCLUDED_

typedef unsigned ngx_uint_t;
typedef int      ngx_int_t;
typedef ngx_list_part_s ngx_list_part_t;

struct ngx_list_part_s {
    void             *elts;
    ngx_uint_t        nelts;
    ngx_list_part_t  *next;
};


typedef struct {
    ngx_list_part_t  *last;
    ngx_list_part_t   part;
    size_t            size;
    ngx_uint_t        nalloc;
    ngx_pool_t       *pool;
} ngx_list_t;


ngx_int_t  ngx_list_init(ngx_list_t *list, size_t size, ngx_uint_t n, ngx_pool_t *pool);
ngx_list_t *ngx_list_create(size_t size, ngx_uint_t n, ngx_pool_t *pool);
void *ngx_list_push(ngx_list_t *list);


#endif