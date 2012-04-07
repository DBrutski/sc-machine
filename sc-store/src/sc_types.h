#ifndef _sc_types_h_
#define _sc_types_h_

//! Structure to store element uri
struct _sc_uri
{
  unsigned int seg;
  unsigned int id;
};

#define uri_empty(uri) ((uri.seg == -1) && (uri.id == -1))

#define uri_eq(uri1, uri2) ((uri1.seg == uri2.seg) && (uri1.id == uri2.id))

typedef unsigned int sc_type;

//! sc-element types
#define sc_type_node 1
#define sc_type_arc 1 << 1

//! constant types
#define sc_type_const 1 << 2 
#define sc_type_var 1 << 3
#define sc_type_meta 1 << 4

//! Positive types for arcs
#define sc_type_pos 1 << 5
#define sc_type_neg 1 << 6
#define sc_type_fuz 1 << 7

//! Temporary type
#define sc_type_temp 1 << 8


typedef struct _sc_arc  sc_arc;
typedef struct _sc_content sc_content;
typedef struct _sc_incident_info sc_incident_info;
typedef struct _sc_element sc_element;
typedef struct _sc_segment sc_segment;
typedef struct _sc_uri sc_uri;
typedef struct _sc_elements_stat sc_elements_stat;
typedef struct _sc_iterator_param sc_iterator_param;
typedef struct _sc_iterator sc_iterator;


#endif