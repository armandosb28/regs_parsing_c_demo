/*
 ============================================================================
 Name        : regs_parsing_c_demo.c
 Author      : Armando Sandoval
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ENUMS */
enum reg_type_a {
	REG_TA_0,
	REG_TA_1,
	REG_TA_2,
	REG_TA_3,
	REG_TA_MAX
};

enum reg_types {
	COMMON,
	SPEED_0,
	SPEED_1,
	SPEED_2,
	SPEED_MAX
};

enum reg_type_b {
	REG_TB_0,
	REG_TB_1_0,
	REG_TB_1_1,
	REG_TB_1_2,
	REG_TB_2,
	REG_TB_3_0,
	REG_TB_3_1,
	REG_TB_MAX
};

/* STRUCTS */

struct reg_general_type {
	int reg_base;
	int index;
	int type;
};

const struct reg_general_type reg_parsing [REG_TA_MAX] [SPEED_MAX] = {
	[REG_TA_0] = {{
					.reg_base = REG_TB_0,
					.index    = 100,
					.type     = COMMON
	}},
	[REG_TA_1] = {
			[SPEED_0] = {
							.reg_base = REG_TB_1_0,
							.index    = 100,
							.type     = SPEED_0
			},
			[SPEED_1] = {
							.reg_base = REG_TB_1_1,
							.index    = 101,
							.type     = SPEED_1
			},
			[SPEED_2] = {
							.reg_base = REG_TB_1_2,
							.index    = 102,
							.type     = SPEED_2
						}
	},
	[REG_TA_2] = {{
					.reg_base = REG_TB_2,
					.index    = 100,
					.type     = COMMON
	}},
	[REG_TA_3] = {
			[SPEED_0] = {
							.reg_base = REG_TB_3_0,
							.index    = 100,
							.type     = SPEED_0
						},
			[SPEED_1] = {
							.reg_base = REG_TB_3_1,
							.index    = 101,
							.type     = SPEED_1
						}
	}
};

static struct reg_general_type parse_registers (enum reg_type_a reg_ta, enum reg_types reg_speed)
{
	return reg_parsing [reg_ta] [reg_speed];
};

int main(void) {

	enum reg_type_a         reg_ta      = REG_TA_1;
	enum reg_types          reg_speed   = COMMON;
	struct reg_general_type reg_tb_info = { 0 };

	reg_tb_info = parse_registers (reg_ta, reg_speed);

	printf("reg_tb_base:  %i\nreg_tb_index: %i\nreg_tb_type:  %i\n",\
			reg_tb_info.reg_base,\
			reg_tb_info.index,\
			reg_tb_info.type);

	return EXIT_SUCCESS;
}


