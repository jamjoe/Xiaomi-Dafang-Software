#ifndef _CLK_H_
#define _CLK_H_
#include <linux/init.h>
#include <linux/kernel.h>
struct clk;
struct cpm_pwc;
struct clk_ops {
	int (*enable)(struct clk *,int);
	struct clk* (*get_parent)(struct clk *);
	int (*set_parent)(struct clk *,struct clk *);
	unsigned long (*get_rate)(struct clk *);
	int (*set_rate)(struct clk *,unsigned long);
	int (*set_round_rate)(struct clk *,unsigned long);
};
struct clk {
	const char *name;
	unsigned long rate;
	struct clk *parent;
	unsigned long flags;
#define CLK_FLG_NOALLOC	BIT(0)
#define CLK_FLG_ENABLE	BIT(1)
#define CLK_GATE_BIT(flg)	((flg) >> 24)
#define CLK_FLG_GATE	BIT(2)
#define CLK_CPCCR_NO(flg)	(((flg) >> 24) & 0xff)
#define CLK_FLG_CPCCR	BIT(3)
#define CLK_CGU_NO(flg) 	(((flg) >> 24) & 0xff)
#define CLK_FLG_CGU	BIT(4)
#define CLK_PLL_NO(flg) 	(((flg) >> 24) & 0xff)
#define CLK_FLG_PLL	BIT(5)
#define CLK_PWC_NO(flg) 	(((flg) >> 24) & 0xff)
#define CLK_FLG_PWC	BIT(6)
#define CLK_PARENT(flg) 	(((flg) >> 16) & 0xff)
#define CLK_RELATIVE(flg) 	(((flg) >> 16) & 0xff)
#define CLK_FLG_PARENT	BIT(7)
#define CLK_FLG_RELATIVE BIT(8)
	struct clk_ops *ops;
	int count;
	int init_state;
	struct clk *source;
	struct clk *child;
	unsigned int CLK_ID;
};

enum {
	CLK_ID_EXT     = 0,
	CLK_ID_EXT0,
#define CLK_NAME_EXT0		"ext0"
	CLK_ID_EXT1,
#define CLK_NAME_EXT1		"ext1"
	CLK_ID_OTGPHY,
#define CLK_NAME_OTGPHY	        "otg_phy"

	CLK_ID_PLL,
	CLK_ID_APLL,
#define CLK_NAME_APLL		"apll"
	CLK_ID_MPLL,
#define CLK_NAME_MPLL		"mpll"
	CLK_ID_SCLKA,
#define CLK_NAME_SCLKA		"sclka"
	/**********************************************************************************/
	CLK_ID_CPPCR,
	CLK_ID_CCLK,
#define CLK_NAME_CCLK		"cclk"
	CLK_ID_L2CLK,
#define CLK_NAME_L2CLK		"l2clk"
	CLK_ID_H0CLK,
#define CLK_NAME_H0CLK		"h0clk"
	CLK_ID_H2CLK,
#define CLK_NAME_H2CLK		"h2clk"
	CLK_ID_PCLK,
#define CLK_NAME_PCLK		"pclk"
	CLK_ID_MSC,
#define CLK_NAME_MSC		"msc"
	/**********************************************************************************/
/**********************************************************************************/
	CLK_ID_CGU,
	CLK_ID_CGU_BCH,
#define CLK_NAME_CGU_BCH	"cgu_bch"
	CLK_ID_CGU_ISP,
#define CLK_NAME_CGU_ISP	"cgu_isp"
	CLK_ID_CGU_GPU,
#define CLK_NAME_CGU_GPU	"cgu_gpu"
	CLK_ID_CGU_PCM,
#define CLK_NAME_CGU_PCM	"cgu_pcm"
	CLK_ID_CGU_CIM,
#define CLK_NAME_CGU_CIM	"cgu_cim"
	CLK_ID_CGU_SSI,
#define CLK_NAME_CGU_SSI	"cgu_ssi"
	CLK_ID_CGU_MSC_MUX,
#define CLK_NAME_CGU_MSC_MUX	"cgu_msc_mux"
	CLK_ID_CGU_UHC,
#define CLK_NAME_CGU_UHC	"cgu_uhc"
	CLK_ID_CGU_MSC2,
#define CLK_NAME_CGU_MSC2	"cgu_msc2"
	CLK_ID_CGU_MSC1,
#define CLK_NAME_CGU_MSC1	"cgu_msc1"
	CLK_ID_CGU_MSC0,
#define CLK_NAME_CGU_MSC0	"cgu_msc0"
	CLK_ID_CGU_LPC,
#define CLK_NAME_CGU_LPC	"cgu_lpc"
	CLK_ID_CGU_I2S,
#define CLK_NAME_CGU_I2S	"cgu_i2s"
	CLK_ID_CGU_USB,
#define CLK_NAME_CGU_USB	"cgu_usb"
	CLK_ID_CGU_VPU,
#define CLK_NAME_CGU_VPU	"cgu_vpu"
	CLK_ID_CGU_DDR,
#define CLK_NAME_CGU_DDR	"cgu_ddr"

/**********************************************************************************/
	CLK_ID_DEVICES,
	CLK_ID_DDR,
#define CLK_NAME_DDR		"ddr"
	CLK_ID_TCU,
#define CLK_NAME_TCU		"tcu"
	CLK_ID_RTC,
#define CLK_NAME_RTC		"rtc"
	CLK_ID_DES,
#define CLK_NAME_DES		"des"
	CLK_ID_PCM,
#define CLK_NAME_PCM		"pcm"
	CLK_ID_DSI,
#define CLK_NAME_DSI		"dsi"
	CLK_ID_CSI,
#define CLK_NAME_CSI		"csi"
	CLK_ID_LCD,
#define CLK_NAME_LCD		"lcd"

	CLK_ID_ISP,
#define CLK_NAME_ISP		"isp"
	CLK_ID_UHC,
#define CLK_NAME_UHC		"uhc"
	CLK_ID_PDMA,
#define CLK_NAME_PDMA		"pdma"
	CLK_ID_SSI2,
#define CLK_NAME_SSI2		"ssi2"
	CLK_ID_SSI1,
#define CLK_NAME_SSI1		"ssi1"
	CLK_ID_UART4,
#define CLK_NAME_UART4		"uart4"
	CLK_ID_UART3,
#define CLK_NAME_UART3		"uart3"
	CLK_ID_UART2,
#define CLK_NAME_UART2		"uart2"

	CLK_ID_UART1,
#define CLK_NAME_UART1		"uart1"
	CLK_ID_UART0,
#define CLK_NAME_UART0		"uart0"
	CLK_ID_SADC,
#define CLK_NAME_SADC		"sadc"
	CLK_ID_MSC2,
#define CLK_NAME_MSC2		"msc2"
	CLK_ID_AIC,
#define CLK_NAME_AIC		"aic"
	CLK_ID_I2C3,
#define CLK_NAME_I2C3		"i2c3"
	CLK_ID_I2C2,
#define CLK_NAME_I2C2		"i2c2"
	CLK_ID_I2C1,
#define CLK_NAME_I2C1		"i2c1"

	CLK_ID_I2C0,
#define CLK_NAME_I2C0		"i2c0"
	CLK_ID_SSI0,
#define CLK_NAME_SSI0		"ssi0"
	CLK_ID_MSC1,
#define CLK_NAME_MSC1		"msc1"
	CLK_ID_MSC0,
#define CLK_NAME_MSC0		"msc0"
	CLK_ID_OTG,
#define CLK_NAME_OTG		"otg1"
	CLK_ID_BCH,
#define CLK_NAME_BCH		"bch"
	CLK_ID_NEMC,
#define CLK_NAME_NEMC		"nemc"
	CLK_ID_NFI,
#define CLK_NAME_NFI		"nfi"

	CLK_ID_CPU,
#define CLK_NAME_CPU		"cpu"
	CLK_ID_APB0,
#define CLK_NAME_APB0		"apb0"
	CLK_ID_DLINE,
#define CLK_NAME_DLINE		"dline"
	CLK_ID_TCU_EXCLK,
#define CLK_NAME_TCU_EXCLK	"tcu_exclk"
	CLK_ID_SYS_OST,
#define CLK_NAME_SYS_OST	"sys_ost"
	CLK_ID_AHB0,
#define CLK_NAME_AHB0	        "ahb0"
	CLK_ID_P0,
#define CLK_NAME_P0	        "p0"
	CLK_ID_P1,
#define CLK_NAME_P1	        "p1"

	CLK_ID_DMIC,
#define CLK_NAME_DMIC	        "dmic"
	CLK_ID_HASH,
#define CLK_NAME_HASH	        "hash"
	CLK_ID_AES,
#define CLK_NAME_AES	        "aes"
	CLK_ID_EPD,
#define CLK_NAME_EPD	        "epd"
	CLK_ID_AHB_MON,
#define CLK_NAME_AHB_MON	"ahb_mon"
	CLK_ID_IPU,
#define CLK_NAME_IPU	        "ipu"
	CLK_ID_GPU,
#define CLK_NAME_GPU	        "gpu"
	CLK_ID_VPU,
#define CLK_NAME_VPU	        "vpu"
	CLK_ID_PWC,
	CLK_ID_PWC_P0,
#define CLK_NAME_PWC_P0	         "pwc_p0"
	CLK_ID_PWC_P1,
#define CLK_NAME_PWC_P1	         "pwc_p1"
	CLK_ID_PWC_VPU,
#define CLK_NAME_PWC_VPU         "pwc_vpu"
	CLK_ID_PWC_GPU,
#define CLK_NAME_PWC_GPU         "pwc_gpu"
	CLK_ID_PWC_ISP,
#define CLK_NAME_PWC_ISP         "pwc_isp"
	CLK_ID_PWC_IPU,
#define CLK_NAME_PWC_IPU         "pwc_ipu"
	CLK_ID_PWC_DMIC,
#define CLK_NAME_PWC_DMIC        "pwc_dmic"
	CLK_ID_PWC_BCH,
#define CLK_NAME_PWC_BCH         "pwc_bch"
	CLK_ID_PWC_HASH,
#define CLK_NAME_PWC_HASH        "pwc_hash"
	CLK_ID_PWC_LCD,
#define CLK_NAME_PWC_LCD         "pwc_lcd"
	CLK_ID_PWC_USB,
#define CLK_NAME_PWC_USB         "pwc_usb"
	CLK_ID_PWC_UHC,
#define CLK_NAME_PWC_UHC         "pwc_uhc"

	CLK_ID_STOP,
	CLK_ID_INVALID,
};


enum {
	CGU_BCH,CGU_ISP, CGU_GPU, CGU_PCM, CGU_CIM,CGU_SSI,
	CGU_UHC,CGU_MSC2,CGU_MSC1,CGU_MSC0,CGU_LPC,CGU_I2S,
	CGU_USB,CGU_VPU, CGU_DDR, CGU_MSC_MUX
};

enum {
	CDIV = 0,L2CDIV,H0DIV,H2DIV,PDIV,SCLKA,
};
enum {
	PWC_P0 = 0,PWC_P1,PWC_VPU,PWC_GPU,PWC_ISP,PWC_IPU,PWC_DMIC,
	PWC_BCH,PWC_HASH,PWC_LCD,PWC_USB,PWC_UHC,
};
struct  freq_udelay_jiffy {
	unsigned int  max_num;
	unsigned int  cpufreq;
	unsigned int  udelay_val;
	unsigned int  loops_per_jiffy;
};

int get_clk_sources_size(void);
struct clk *get_clk_from_id(int clk_id);
int get_clk_id(struct clk *clk);
//typedef int (*DUMP_CALLBACK)(char *, const char *, ...);
//int dump_out_clk(char *str);

void __init init_cgu_clk(struct clk *clk);
void __init init_cpccr_clk(struct clk *clk);
void __init init_ext_pll(struct clk *clk);
void __init init_gate_clk(struct clk *clk);
void __init cpm_pwc_init(void);
void __init init_pwc_clk(struct clk *clk);
int cpm_pwc_enable_ctrl(struct clk *clk,int on);
void cpm_pwc_suspend(void);
void cpm_pwc_resume(void);
#endif /* _CLK_H_ */
