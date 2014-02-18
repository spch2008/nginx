#ifndef _NGX_QUEUE_H_INCLUDED_H_
#define _NGX_QUEUE_H_INCLUDED_H_

typedef ngx_queue_s ngx_queue_t;

struct ngx_queue_s {
    ngx_queue_t  *prev;
    ngx_queue_t  *next;
};


#define ngx_queue_init(q)                        \
    (q)->next = q;                               \
    (q)->prev = q
    
#define ngx_queue_empty(h)                       \
    ((h) == (h)->prev)
    
#define ngx_queue_insert_head(h, x)              \
    (x)->next = (h)->next;                       \
    (x)->next->prev = x;                         \
    (x)->prev = h;                               \
    (h)->next = x
    
#define ngx_queue_insert_tail(h, x)              \
    (x)->prev = (h)->prev;                       \
    (x)->prev->next = x;                         \
    (x)->next = h;                               \
    (h)->prev = x
    
#define ngx_queue_insert_after ngx_queue_insert_head
    
#define ngx_queue_head(h)                        \
    (h)->next
    
#define ngx_queue_last(h)                        \
    (h)->prev
    
    
#define ngx_queue_sentinel(h)                    \
    (h)
    
    
#define ngx_queue_next(q)                        \
    (q)->next

#define ngx_queue_prev(q)                        \
    (q)->prev
    
#define ngx_queue_remove(x)                      \
    (x)->next->prev = (x)->prev;                 \
    (x)->prev->next = (x)->next
    
#define ngx_queue_add(h, n)                      \
    (h)->prev->next = (n)->next;                 \
    (n)->next->prev = (h)->prev;                 \
    (h)->prev       = (n)->prev;                 \
    (n)->prev->next = h
    
    
ngx_queue_t *ngx_queue_middle(ngx_queue_t *queue);
void ngx_queue_sort(ngx_queue_t *queue,
    ngx_int_t (*cmp)(const ngx_queue_t *, const ngx_queue_t *));



#endif