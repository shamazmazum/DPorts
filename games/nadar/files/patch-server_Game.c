
$FreeBSD: head/games/nadar/files/patch-server_Game.c 340725 2014-01-22 17:40:44Z mat $

--- server/Game.c.orig	Sun Aug 22 16:35:40 2004
+++ server/Game.c	Sun Aug 22 16:35:50 2004
@@ -226,7 +226,7 @@
       case PLAYER_DESTROY : /* Destroy 状態の Player を削除する */
 	current = ObjList_DeleteObjToPrev(game->player_list, current);
 	break;
-      default :
+      default : break;
       }
     }
 
