/********************************************************************[libaroma]*
 * Copyright (C) 2011-2015 Ahmad Amarullah (http://amarullz.com/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *______________________________________________________________________________
 *
 * Filename    : ctl_scroll.h
 * Description : scroll control
 *
 * + This is part of libaroma, an embedded ui toolkit.
 * + 12/02/15 - Author(s): Ahmad Amarullah
 *
 */
#ifndef __libaroma_aroma_h__
  #error "Include <aroma.h> instead."
#endif
#ifndef __libaroma_ctl_scroll_h__
#define __libaroma_ctl_scroll_h__

typedef struct _LIBAROMA_CTL_SCROLL_CLIENT LIBAROMA_CTL_SCROLL_CLIENT;
typedef struct _LIBAROMA_CTL_SCROLL_CLIENT * LIBAROMA_CTL_SCROLL_CLIENTP;

/*
 * Typedef     : LIBAROMA_CTL_SCROLLCB_*
 * Descriptions: scroll callbacks
 */
typedef void (*LIBAROMA_CTL_SCROLLCB_DRAW) \
  (LIBAROMA_CONTROLP, LIBAROMA_CTL_SCROLL_CLIENTP, \
    LIBAROMA_CANVASP, int, int, int, int);
  /* ctl, client, canvas, x, y, w, h */
typedef void (*LIBAROMA_CTL_SCROLLCB_DESTROY) \
  (LIBAROMA_CONTROLP, LIBAROMA_CTL_SCROLL_CLIENTP);
  /* ctl, client */
typedef byte (*LIBAROMA_CTL_SCROLLCB_THREAD) \
  (LIBAROMA_CONTROLP, LIBAROMA_CTL_SCROLL_CLIENTP);
  /* ctl, client - return = should_redraw */
typedef dword (*LIBAROMA_CTL_SCROLLCB_MESSAGE) \
  (LIBAROMA_CONTROLP, LIBAROMA_CTL_SCROLL_CLIENTP, \
    LIBAROMA_MSGP, int, int);
  /* ctl, client, message, client_x, client_y - return command */

/*
 * Structure   : _LIBAROMA_CTL_SCROLL_CLIENT
 * Typedef     : LIBAROMA_CTL_SCROLL_CLIENT, * LIBAROMA_CTL_SCROLL_CLIENTP
 * Descriptions: scroll client
 */
struct _LIBAROMA_CTL_SCROLL_CLIENT{
  byte signature;
  voidp internal;
  LIBAROMA_CTL_SCROLLCB_MESSAGE message;
  LIBAROMA_CTL_SCROLLCB_DRAW draw;
  LIBAROMA_CTL_SCROLLCB_DESTROY destroy;
  LIBAROMA_CTL_SCROLLCB_THREAD thread;
};

/*
 * Function    : libaroma_ctl_scroll_set_client
 * Return Value: byte
 * Descriptions: set client handler
 */
byte libaroma_ctl_scroll_set_client(
    LIBAROMA_CONTROLP ctl,
    voidp internal,
    byte client_signature,
    LIBAROMA_CTL_SCROLLCB_MESSAGE message,
    LIBAROMA_CTL_SCROLLCB_DRAW draw,
    LIBAROMA_CTL_SCROLLCB_DESTROY destroy,
    LIBAROMA_CTL_SCROLLCB_THREAD thread
);

/*
 * Function    : libaroma_ctl_scroll_set_height
 * Return Value: byte
 * Descriptions: set scroll height
 */
byte libaroma_ctl_scroll_set_height(LIBAROMA_CONTROLP ctl, int h);

/*
 * Function    : libaroma_ctl_scroll_set_pos
 * Return Value: byte
 * Descriptions: set scroll position
 */
byte libaroma_ctl_scroll_set_pos(LIBAROMA_CONTROLP ctl, int scroll_y);

/*
 * Function    : libaroma_ctl_scroll_is_visible
 * Return Value: byte
 * Descriptions: is this area visible?
 */
byte libaroma_ctl_scroll_is_visible(
   LIBAROMA_CONTROLP ctl, int y, int h
);

/*
 * Function    : libaroma_ctl_scroll_sync
 * Return Value: byte
 * Descriptions: sync client drawing
 */
byte libaroma_ctl_scroll_sync(
   LIBAROMA_CONTROLP ctl, 
   LIBAROMA_CANVASP canvas,
   int x, int y, int w, int h,
   byte erase
);

/*
 * Function    : libaroma_ctl_scroll
 * Return Value: LIBAROMA_CONTROLP
 * Descriptions: create button control
 */
LIBAROMA_CONTROLP libaroma_ctl_scroll(
    LIBAROMA_WINDOWP win, word id,
    int x, int y, int w, int h
);



/* test */
LIBAROMA_CONTROLP libaroma_ctl_testscroll(
    LIBAROMA_WINDOWP win, word id,
    int x, int y, int w, int h
);


#endif /* __libaroma_ctl_scroll_h__ */
