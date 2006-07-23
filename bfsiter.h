/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2006  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef PYTHON_BFSITER_H
#define PYTHON_BFSITER_H

#include <Python.h>
#include "graphobject.h"

/**
 * \ingroup python_interface_bfsiter
 * \brief A structure representing a BFS iterator of a graph
 */
typedef struct
{
  PyObject_HEAD
  PyObject *gref;
  igraph_dqueue_t queue;
  igraph_vector_t neis;
  igraph_t *graph;
  char *visited;
  igraph_neimode_t mode;
  igraph_bool_t advanced;
} igraphmodule_BFSIterObject;

PyObject* igraphmodule_BFSIter_new(igraphmodule_GraphObject *g, PyObject *o, igraph_neimode_t mode, igraph_bool_t advanced);
int igraphmodule_BFSIter_traverse(igraphmodule_BFSIterObject *self,
				  visitproc visit, void *arg);
int igraphmodule_BFSIter_clear(igraphmodule_BFSIterObject *self);
void igraphmodule_BFSIter_dealloc(igraphmodule_BFSIterObject* self);

extern PyTypeObject igraphmodule_BFSIterType;

#endif