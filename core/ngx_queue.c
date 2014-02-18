#include "ngx_queue.h"

ngx_queue_t *
ngx_queue_middle(ngx_queue_t *queue)
{
    ngx_queue_t *middle, *next;
    
    middle = ngx_queue_head(queue);
    if (middle == ngx_queue_last(queue)) {
        return middle;
    }
    
    next = ngx_queue_head(queue);
    
    for ( ; ;) {
        middle = ngx_queue_next(middle);
        next = ngx_queue_next(next);
        
        if (next == ngx_queue_last(queue)) {
            return middle;
        }
        
        next = ngx_queue_next(next);
        if (next == ngx_queue_last(queue)) {
            return middle;
        }
    }
}