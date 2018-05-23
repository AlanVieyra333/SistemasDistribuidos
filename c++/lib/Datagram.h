#ifndef DATAGRAM_H_
#define DATAGRAM_H_

enum {
  START_SPIDER,
  OBJECTIVE_SPIDER,
  PLAYING,
  END_GAME,
  COLLISION,
};

typedef struct {
  int msg_id;
  int id_spider;
  double x;
  double y;
  double distance;
} Datagram;

#endif
