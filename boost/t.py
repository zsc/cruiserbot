from pylgbst import get_connection_auto
from pylgbst.movehub import MoveHub

conn=get_connection_auto()  # ! don't put this into `try` block
try:
    hub = MoveHub(conn)
finally:
    conn.disconnect()
