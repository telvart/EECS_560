#include "BNode.h"


BNode::BNode(int val)
{
  m_order=0;
  m_key=val;
  m_left=nullptr;
  m_right=nullptr;
  m_firstChild=nullptr;
}
