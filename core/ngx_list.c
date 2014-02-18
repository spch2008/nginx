#include "ngx_list.h"



ngx_int_t  ngx_list_init(ngx_list_t *list, size_t size, ngx_uint_t n, ngx_pool_t *pool)
{
    list->part.elts = ngx_alloc(pool, size * n);
    if (list->part.elts == NULL) {
        return NGX_ERROR;
    }
    
    list->part.nelts = 0;
    list->part.next  = NULL;
    
    list->last = &list->part;
    list->size = size;
    list->nalloc = n;
    list->pool   = pool;
    
    return NGX_OK;
}

ngx_list_t *ngx_list_create(size_t size, ngx_uint_t n, ngx_pool_t *pool)
{
    ngx_list_t *list;
    
    list = ngx_alloc(pool, sizeof(ngx_list_t));
    if (list == NULL) {
        return NULL;
    }
    
    list->part.elts = ngx_alloc(pool, size * n);
    if (list->part.elts == NULL) {
        return NULL;
    }
    
    list->part.nelts = 0;
    list->part.next  = NULL;
    
    list->last = &list->part;
    list->size = size;
    list->nalloc = n;
    list->pool   = pool;
    
    return list;
}



void *ngx_list_push(ngx_list_t *list)
{
    ngx_list_part_t *last;
    void *elts;
    
    last = list->last;
    if (last->elts == list->nalloc) {
    
        last = ngx_alloc(list->pool, sizeof(ngx_list_part_t));
        if (last == NULL) {
            return NULL;
        }
        
        last->elts = ngx_alloc(list->pool, list->size * list->nalloc);
        if (last->elts == NULL) {
            return NULL;
        }
        
        last->nelts = 0;
        last->next  = NULL;
        
        list->last->next = last;
        list->last = last;
    }
    
    elts = (char*)last->elts + list->size * last->nelts;
    last->nelts++;
    
    return elts;
}