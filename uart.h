
extern volatile uint8_t rcv_over;
extern volatile uint8_t  rcv_cnt;



void comm_cmd(void);

uint16_t buf_crc_cal(uint8_t *buf, uint16_t size);

void  resp_ctsu_read(void);

void uart_1_ini(void);

void p03_rxd1_p04_txd1(void);

