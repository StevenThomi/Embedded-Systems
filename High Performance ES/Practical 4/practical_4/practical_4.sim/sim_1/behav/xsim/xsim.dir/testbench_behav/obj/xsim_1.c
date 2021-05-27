/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2020 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

#if defined(_WIN32)
 #include "stdio.h"
 #define IKI_DLLESPEC __declspec(dllimport)
#else
 #define IKI_DLLESPEC
#endif
#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2020 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

#if defined(_WIN32)
 #include "stdio.h"
 #define IKI_DLLESPEC __declspec(dllimport)
#else
 #define IKI_DLLESPEC
#endif
#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
typedef void (*funcp)(char *, char *);
extern int main(int, char**);
IKI_DLLESPEC extern void execute_2(char*, char *);
IKI_DLLESPEC extern void execute_4(char*, char *);
IKI_DLLESPEC extern void execute_5(char*, char *);
IKI_DLLESPEC extern void execute_6(char*, char *);
IKI_DLLESPEC extern void execute_1302(char*, char *);
IKI_DLLESPEC extern void execute_80(char*, char *);
IKI_DLLESPEC extern void execute_1292(char*, char *);
IKI_DLLESPEC extern void execute_1293(char*, char *);
IKI_DLLESPEC extern void execute_1294(char*, char *);
IKI_DLLESPEC extern void execute_1295(char*, char *);
IKI_DLLESPEC extern void execute_1296(char*, char *);
IKI_DLLESPEC extern void execute_69(char*, char *);
IKI_DLLESPEC extern void execute_70(char*, char *);
IKI_DLLESPEC extern void execute_71(char*, char *);
IKI_DLLESPEC extern void execute_72(char*, char *);
IKI_DLLESPEC extern void execute_73(char*, char *);
IKI_DLLESPEC extern void execute_75(char*, char *);
IKI_DLLESPEC extern void execute_77(char*, char *);
IKI_DLLESPEC extern void execute_88(char*, char *);
IKI_DLLESPEC extern void execute_89(char*, char *);
IKI_DLLESPEC extern void execute_90(char*, char *);
IKI_DLLESPEC extern void execute_91(char*, char *);
IKI_DLLESPEC extern void execute_92(char*, char *);
IKI_DLLESPEC extern void execute_93(char*, char *);
IKI_DLLESPEC extern void execute_94(char*, char *);
IKI_DLLESPEC extern void execute_95(char*, char *);
IKI_DLLESPEC extern void execute_96(char*, char *);
IKI_DLLESPEC extern void execute_97(char*, char *);
IKI_DLLESPEC extern void execute_98(char*, char *);
IKI_DLLESPEC extern void execute_176(char*, char *);
IKI_DLLESPEC extern void execute_238(char*, char *);
IKI_DLLESPEC extern void execute_702(char*, char *);
IKI_DLLESPEC extern void execute_703(char*, char *);
IKI_DLLESPEC extern void execute_711(char*, char *);
IKI_DLLESPEC extern void execute_719(char*, char *);
IKI_DLLESPEC extern void execute_720(char*, char *);
IKI_DLLESPEC extern void execute_173(char*, char *);
IKI_DLLESPEC extern void execute_174(char*, char *);
IKI_DLLESPEC extern void execute_175(char*, char *);
IKI_DLLESPEC extern void execute_243(char*, char *);
IKI_DLLESPEC extern void execute_245(char*, char *);
IKI_DLLESPEC extern void execute_270(char*, char *);
IKI_DLLESPEC extern void execute_248(char*, char *);
IKI_DLLESPEC extern void execute_249(char*, char *);
IKI_DLLESPEC extern void execute_273(char*, char *);
IKI_DLLESPEC extern void execute_709(char*, char *);
IKI_DLLESPEC extern void execute_706(char*, char *);
IKI_DLLESPEC extern void execute_707(char*, char *);
IKI_DLLESPEC extern void execute_715(char*, char *);
IKI_DLLESPEC extern void execute_716(char*, char *);
IKI_DLLESPEC extern void execute_717(char*, char *);
IKI_DLLESPEC extern void execute_194(char*, char *);
IKI_DLLESPEC extern void execute_195(char*, char *);
IKI_DLLESPEC extern void execute_207(char*, char *);
IKI_DLLESPEC extern void execute_185(char*, char *);
IKI_DLLESPEC extern void execute_191(char*, char *);
IKI_DLLESPEC extern void execute_192(char*, char *);
IKI_DLLESPEC extern void execute_189(char*, char *);
IKI_DLLESPEC extern void execute_197(char*, char *);
IKI_DLLESPEC extern void execute_199(char*, char *);
IKI_DLLESPEC extern void execute_201(char*, char *);
IKI_DLLESPEC extern void execute_203(char*, char *);
IKI_DLLESPEC extern void execute_205(char*, char *);
IKI_DLLESPEC extern void execute_266(char*, char *);
IKI_DLLESPEC extern void execute_267(char*, char *);
IKI_DLLESPEC extern void execute_269(char*, char *);
IKI_DLLESPEC extern void execute_258(char*, char *);
IKI_DLLESPEC extern void execute_263(char*, char *);
IKI_DLLESPEC extern void execute_264(char*, char *);
IKI_DLLESPEC extern void execute_261(char*, char *);
IKI_DLLESPEC extern void execute_279(char*, char *);
IKI_DLLESPEC extern void execute_695(char*, char *);
IKI_DLLESPEC extern void execute_696(char*, char *);
IKI_DLLESPEC extern void execute_282(char*, char *);
IKI_DLLESPEC extern void execute_284(char*, char *);
IKI_DLLESPEC extern void execute_286(char*, char *);
IKI_DLLESPEC extern void execute_325(char*, char *);
IKI_DLLESPEC extern void execute_326(char*, char *);
IKI_DLLESPEC extern void execute_329(char*, char *);
IKI_DLLESPEC extern void execute_670(char*, char *);
IKI_DLLESPEC extern void execute_671(char*, char *);
IKI_DLLESPEC extern void execute_686(char*, char *);
IKI_DLLESPEC extern void execute_669(char*, char *);
IKI_DLLESPEC extern void execute_674(char*, char *);
IKI_DLLESPEC extern void execute_675(char*, char *);
IKI_DLLESPEC extern void execute_292(char*, char *);
IKI_DLLESPEC extern void execute_293(char*, char *);
IKI_DLLESPEC extern void execute_294(char*, char *);
IKI_DLLESPEC extern void execute_300(char*, char *);
IKI_DLLESPEC extern void execute_318(char*, char *);
IKI_DLLESPEC extern void execute_319(char*, char *);
IKI_DLLESPEC extern void execute_321(char*, char *);
IKI_DLLESPEC extern void execute_309(char*, char *);
IKI_DLLESPEC extern void execute_315(char*, char *);
IKI_DLLESPEC extern void execute_316(char*, char *);
IKI_DLLESPEC extern void execute_313(char*, char *);
IKI_DLLESPEC extern void execute_679(char*, char *);
IKI_DLLESPEC extern void execute_338(char*, char *);
IKI_DLLESPEC extern void execute_341(char*, char *);
IKI_DLLESPEC extern void execute_400(char*, char *);
IKI_DLLESPEC extern void execute_437(char*, char *);
IKI_DLLESPEC extern void execute_438(char*, char *);
IKI_DLLESPEC extern void execute_349(char*, char *);
IKI_DLLESPEC extern void execute_350(char*, char *);
IKI_DLLESPEC extern void execute_372(char*, char *);
IKI_DLLESPEC extern void execute_373(char*, char *);
IKI_DLLESPEC extern void execute_352(char*, char *);
IKI_DLLESPEC extern void execute_353(char*, char *);
IKI_DLLESPEC extern void execute_354(char*, char *);
IKI_DLLESPEC extern void execute_355(char*, char *);
IKI_DLLESPEC extern void execute_357(char*, char *);
IKI_DLLESPEC extern void execute_358(char*, char *);
IKI_DLLESPEC extern void execute_359(char*, char *);
IKI_DLLESPEC extern void execute_360(char*, char *);
IKI_DLLESPEC extern void execute_362(char*, char *);
IKI_DLLESPEC extern void execute_363(char*, char *);
IKI_DLLESPEC extern void execute_364(char*, char *);
IKI_DLLESPEC extern void execute_365(char*, char *);
IKI_DLLESPEC extern void execute_367(char*, char *);
IKI_DLLESPEC extern void execute_368(char*, char *);
IKI_DLLESPEC extern void execute_369(char*, char *);
IKI_DLLESPEC extern void execute_370(char*, char *);
IKI_DLLESPEC extern void execute_404(char*, char *);
IKI_DLLESPEC extern void execute_405(char*, char *);
IKI_DLLESPEC extern void execute_406(char*, char *);
IKI_DLLESPEC extern void execute_409(char*, char *);
IKI_DLLESPEC extern void execute_442(char*, char *);
IKI_DLLESPEC extern void execute_443(char*, char *);
IKI_DLLESPEC extern void execute_447(char*, char *);
IKI_DLLESPEC extern void execute_490(char*, char *);
IKI_DLLESPEC extern void execute_491(char*, char *);
IKI_DLLESPEC extern void execute_494(char*, char *);
IKI_DLLESPEC extern void execute_495(char*, char *);
IKI_DLLESPEC extern void execute_496(char*, char *);
IKI_DLLESPEC extern void execute_497(char*, char *);
IKI_DLLESPEC extern void execute_498(char*, char *);
IKI_DLLESPEC extern void execute_499(char*, char *);
IKI_DLLESPEC extern void execute_500(char*, char *);
IKI_DLLESPEC extern void execute_501(char*, char *);
IKI_DLLESPEC extern void execute_582(char*, char *);
IKI_DLLESPEC extern void execute_583(char*, char *);
IKI_DLLESPEC extern void execute_584(char*, char *);
IKI_DLLESPEC extern void execute_585(char*, char *);
IKI_DLLESPEC extern void execute_390(char*, char *);
IKI_DLLESPEC extern void execute_391(char*, char *);
IKI_DLLESPEC extern void execute_399(char*, char *);
IKI_DLLESPEC extern void execute_381(char*, char *);
IKI_DLLESPEC extern void execute_387(char*, char *);
IKI_DLLESPEC extern void execute_388(char*, char *);
IKI_DLLESPEC extern void execute_385(char*, char *);
IKI_DLLESPEC extern void execute_393(char*, char *);
IKI_DLLESPEC extern void execute_395(char*, char *);
IKI_DLLESPEC extern void execute_397(char*, char *);
IKI_DLLESPEC extern void execute_464(char*, char *);
IKI_DLLESPEC extern void execute_465(char*, char *);
IKI_DLLESPEC extern void execute_467(char*, char *);
IKI_DLLESPEC extern void execute_455(char*, char *);
IKI_DLLESPEC extern void execute_461(char*, char *);
IKI_DLLESPEC extern void execute_462(char*, char *);
IKI_DLLESPEC extern void execute_459(char*, char *);
IKI_DLLESPEC extern void execute_518(char*, char *);
IKI_DLLESPEC extern void execute_519(char*, char *);
IKI_DLLESPEC extern void execute_521(char*, char *);
IKI_DLLESPEC extern void execute_509(char*, char *);
IKI_DLLESPEC extern void execute_515(char*, char *);
IKI_DLLESPEC extern void execute_516(char*, char *);
IKI_DLLESPEC extern void execute_513(char*, char *);
IKI_DLLESPEC extern void execute_538(char*, char *);
IKI_DLLESPEC extern void execute_539(char*, char *);
IKI_DLLESPEC extern void execute_541(char*, char *);
IKI_DLLESPEC extern void execute_529(char*, char *);
IKI_DLLESPEC extern void execute_535(char*, char *);
IKI_DLLESPEC extern void execute_536(char*, char *);
IKI_DLLESPEC extern void execute_533(char*, char *);
IKI_DLLESPEC extern void execute_692(char*, char *);
IKI_DLLESPEC extern void execute_745(char*, char *);
IKI_DLLESPEC extern void execute_791(char*, char *);
IKI_DLLESPEC extern void execute_979(char*, char *);
IKI_DLLESPEC extern void execute_980(char*, char *);
IKI_DLLESPEC extern void execute_988(char*, char *);
IKI_DLLESPEC extern void execute_996(char*, char *);
IKI_DLLESPEC extern void execute_997(char*, char *);
IKI_DLLESPEC extern void execute_742(char*, char *);
IKI_DLLESPEC extern void execute_743(char*, char *);
IKI_DLLESPEC extern void execute_744(char*, char *);
IKI_DLLESPEC extern void execute_796(char*, char *);
IKI_DLLESPEC extern void execute_798(char*, char *);
IKI_DLLESPEC extern void execute_823(char*, char *);
IKI_DLLESPEC extern void execute_801(char*, char *);
IKI_DLLESPEC extern void execute_802(char*, char *);
IKI_DLLESPEC extern void execute_826(char*, char *);
IKI_DLLESPEC extern void execute_986(char*, char *);
IKI_DLLESPEC extern void execute_983(char*, char *);
IKI_DLLESPEC extern void execute_984(char*, char *);
IKI_DLLESPEC extern void execute_992(char*, char *);
IKI_DLLESPEC extern void execute_993(char*, char *);
IKI_DLLESPEC extern void execute_994(char*, char *);
IKI_DLLESPEC extern void execute_763(char*, char *);
IKI_DLLESPEC extern void execute_764(char*, char *);
IKI_DLLESPEC extern void execute_768(char*, char *);
IKI_DLLESPEC extern void execute_754(char*, char *);
IKI_DLLESPEC extern void execute_760(char*, char *);
IKI_DLLESPEC extern void execute_761(char*, char *);
IKI_DLLESPEC extern void execute_758(char*, char *);
IKI_DLLESPEC extern void execute_766(char*, char *);
IKI_DLLESPEC extern void execute_832(char*, char *);
IKI_DLLESPEC extern void execute_972(char*, char *);
IKI_DLLESPEC extern void execute_973(char*, char *);
IKI_DLLESPEC extern void execute_835(char*, char *);
IKI_DLLESPEC extern void execute_837(char*, char *);
IKI_DLLESPEC extern void execute_839(char*, char *);
IKI_DLLESPEC extern void execute_878(char*, char *);
IKI_DLLESPEC extern void execute_879(char*, char *);
IKI_DLLESPEC extern void execute_882(char*, char *);
IKI_DLLESPEC extern void execute_947(char*, char *);
IKI_DLLESPEC extern void execute_948(char*, char *);
IKI_DLLESPEC extern void execute_963(char*, char *);
IKI_DLLESPEC extern void execute_946(char*, char *);
IKI_DLLESPEC extern void execute_951(char*, char *);
IKI_DLLESPEC extern void execute_952(char*, char *);
IKI_DLLESPEC extern void execute_845(char*, char *);
IKI_DLLESPEC extern void execute_846(char*, char *);
IKI_DLLESPEC extern void execute_847(char*, char *);
IKI_DLLESPEC extern void execute_853(char*, char *);
IKI_DLLESPEC extern void execute_921(char*, char *);
IKI_DLLESPEC extern void execute_889(char*, char *);
IKI_DLLESPEC extern void execute_892(char*, char *);
IKI_DLLESPEC extern void execute_895(char*, char *);
IKI_DLLESPEC extern void execute_896(char*, char *);
IKI_DLLESPEC extern void execute_907(char*, char *);
IKI_DLLESPEC extern void execute_908(char*, char *);
IKI_DLLESPEC extern void execute_928(char*, char *);
IKI_DLLESPEC extern void execute_929(char*, char *);
IKI_DLLESPEC extern void execute_912(char*, char *);
IKI_DLLESPEC extern void execute_913(char*, char *);
IKI_DLLESPEC extern void execute_917(char*, char *);
IKI_DLLESPEC extern void execute_900(char*, char *);
IKI_DLLESPEC extern void execute_969(char*, char *);
IKI_DLLESPEC extern void execute_1022(char*, char *);
IKI_DLLESPEC extern void execute_1068(char*, char *);
IKI_DLLESPEC extern void execute_1256(char*, char *);
IKI_DLLESPEC extern void execute_1257(char*, char *);
IKI_DLLESPEC extern void execute_1265(char*, char *);
IKI_DLLESPEC extern void execute_1273(char*, char *);
IKI_DLLESPEC extern void execute_1274(char*, char *);
IKI_DLLESPEC extern void execute_1019(char*, char *);
IKI_DLLESPEC extern void execute_1020(char*, char *);
IKI_DLLESPEC extern void execute_1021(char*, char *);
IKI_DLLESPEC extern void execute_1073(char*, char *);
IKI_DLLESPEC extern void execute_1075(char*, char *);
IKI_DLLESPEC extern void execute_1100(char*, char *);
IKI_DLLESPEC extern void execute_1078(char*, char *);
IKI_DLLESPEC extern void execute_1079(char*, char *);
IKI_DLLESPEC extern void execute_1103(char*, char *);
IKI_DLLESPEC extern void execute_1263(char*, char *);
IKI_DLLESPEC extern void execute_1260(char*, char *);
IKI_DLLESPEC extern void execute_1261(char*, char *);
IKI_DLLESPEC extern void execute_1269(char*, char *);
IKI_DLLESPEC extern void execute_1270(char*, char *);
IKI_DLLESPEC extern void execute_1271(char*, char *);
IKI_DLLESPEC extern void execute_1109(char*, char *);
IKI_DLLESPEC extern void execute_1249(char*, char *);
IKI_DLLESPEC extern void execute_1250(char*, char *);
IKI_DLLESPEC extern void execute_1112(char*, char *);
IKI_DLLESPEC extern void execute_1114(char*, char *);
IKI_DLLESPEC extern void execute_1116(char*, char *);
IKI_DLLESPEC extern void execute_1155(char*, char *);
IKI_DLLESPEC extern void execute_1156(char*, char *);
IKI_DLLESPEC extern void execute_1159(char*, char *);
IKI_DLLESPEC extern void execute_1224(char*, char *);
IKI_DLLESPEC extern void execute_1225(char*, char *);
IKI_DLLESPEC extern void execute_1240(char*, char *);
IKI_DLLESPEC extern void execute_1223(char*, char *);
IKI_DLLESPEC extern void execute_1228(char*, char *);
IKI_DLLESPEC extern void execute_1229(char*, char *);
IKI_DLLESPEC extern void execute_1198(char*, char *);
IKI_DLLESPEC extern void execute_1166(char*, char *);
IKI_DLLESPEC extern void execute_1169(char*, char *);
IKI_DLLESPEC extern void execute_1172(char*, char *);
IKI_DLLESPEC extern void execute_1173(char*, char *);
IKI_DLLESPEC extern void execute_1184(char*, char *);
IKI_DLLESPEC extern void execute_1185(char*, char *);
IKI_DLLESPEC extern void execute_1205(char*, char *);
IKI_DLLESPEC extern void execute_1206(char*, char *);
IKI_DLLESPEC extern void execute_1189(char*, char *);
IKI_DLLESPEC extern void execute_1190(char*, char *);
IKI_DLLESPEC extern void execute_1194(char*, char *);
IKI_DLLESPEC extern void execute_1177(char*, char *);
IKI_DLLESPEC extern void execute_1246(char*, char *);
IKI_DLLESPEC extern void execute_1290(char*, char *);
IKI_DLLESPEC extern void execute_1291(char*, char *);
IKI_DLLESPEC extern void execute_1298(char*, char *);
IKI_DLLESPEC extern void execute_1299(char*, char *);
IKI_DLLESPEC extern void execute_1300(char*, char *);
IKI_DLLESPEC extern void execute_1301(char*, char *);
IKI_DLLESPEC extern void execute_1304(char*, char *);
IKI_DLLESPEC extern void execute_1305(char*, char *);
IKI_DLLESPEC extern void execute_1306(char*, char *);
IKI_DLLESPEC extern void execute_1307(char*, char *);
IKI_DLLESPEC extern void execute_1308(char*, char *);
IKI_DLLESPEC extern void execute_1309(char*, char *);
IKI_DLLESPEC extern void transaction_1(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_5(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void vhdl_transfunc_eventcallback(char*, char*, unsigned, unsigned, unsigned, char *);
IKI_DLLESPEC extern void transaction_42(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_70(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_119(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_120(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_123(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_124(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_130(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_131(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_134(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_135(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_136(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_143(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_157(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_161(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_168(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_177(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_271(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_491(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_492(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_495(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_496(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_502(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_503(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_506(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_507(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_508(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_515(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_529(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_533(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_540(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_549(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_643(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_744(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_745(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_748(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_749(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_755(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_756(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_759(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_760(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_761(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_768(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_782(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_786(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_793(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_802(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_896(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void vlog_transfunc_eventcallback(char*, char*, unsigned, unsigned, unsigned, char *);
IKI_DLLESPEC extern void transaction_0(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_2(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_3(char*, char*, unsigned, unsigned, unsigned);
IKI_DLLESPEC extern void transaction_4(char*, char*, unsigned, unsigned, unsigned);
funcp funcTab[356] = {(funcp)execute_2, (funcp)execute_4, (funcp)execute_5, (funcp)execute_6, (funcp)execute_1302, (funcp)execute_80, (funcp)execute_1292, (funcp)execute_1293, (funcp)execute_1294, (funcp)execute_1295, (funcp)execute_1296, (funcp)execute_69, (funcp)execute_70, (funcp)execute_71, (funcp)execute_72, (funcp)execute_73, (funcp)execute_75, (funcp)execute_77, (funcp)execute_88, (funcp)execute_89, (funcp)execute_90, (funcp)execute_91, (funcp)execute_92, (funcp)execute_93, (funcp)execute_94, (funcp)execute_95, (funcp)execute_96, (funcp)execute_97, (funcp)execute_98, (funcp)execute_176, (funcp)execute_238, (funcp)execute_702, (funcp)execute_703, (funcp)execute_711, (funcp)execute_719, (funcp)execute_720, (funcp)execute_173, (funcp)execute_174, (funcp)execute_175, (funcp)execute_243, (funcp)execute_245, (funcp)execute_270, (funcp)execute_248, (funcp)execute_249, (funcp)execute_273, (funcp)execute_709, (funcp)execute_706, (funcp)execute_707, (funcp)execute_715, (funcp)execute_716, (funcp)execute_717, (funcp)execute_194, (funcp)execute_195, (funcp)execute_207, (funcp)execute_185, (funcp)execute_191, (funcp)execute_192, (funcp)execute_189, (funcp)execute_197, (funcp)execute_199, (funcp)execute_201, (funcp)execute_203, (funcp)execute_205, (funcp)execute_266, (funcp)execute_267, (funcp)execute_269, (funcp)execute_258, (funcp)execute_263, (funcp)execute_264, (funcp)execute_261, (funcp)execute_279, (funcp)execute_695, (funcp)execute_696, (funcp)execute_282, (funcp)execute_284, (funcp)execute_286, (funcp)execute_325, (funcp)execute_326, (funcp)execute_329, (funcp)execute_670, (funcp)execute_671, (funcp)execute_686, (funcp)execute_669, (funcp)execute_674, (funcp)execute_675, (funcp)execute_292, (funcp)execute_293, (funcp)execute_294, (funcp)execute_300, (funcp)execute_318, (funcp)execute_319, (funcp)execute_321, (funcp)execute_309, (funcp)execute_315, (funcp)execute_316, (funcp)execute_313, (funcp)execute_679, (funcp)execute_338, (funcp)execute_341, (funcp)execute_400, (funcp)execute_437, (funcp)execute_438, (funcp)execute_349, (funcp)execute_350, (funcp)execute_372, (funcp)execute_373, (funcp)execute_352, (funcp)execute_353, (funcp)execute_354, (funcp)execute_355, (funcp)execute_357, (funcp)execute_358, (funcp)execute_359, (funcp)execute_360, (funcp)execute_362, (funcp)execute_363, (funcp)execute_364, (funcp)execute_365, (funcp)execute_367, (funcp)execute_368, (funcp)execute_369, (funcp)execute_370, (funcp)execute_404, (funcp)execute_405, (funcp)execute_406, (funcp)execute_409, (funcp)execute_442, (funcp)execute_443, (funcp)execute_447, (funcp)execute_490, (funcp)execute_491, (funcp)execute_494, (funcp)execute_495, (funcp)execute_496, (funcp)execute_497, (funcp)execute_498, (funcp)execute_499, (funcp)execute_500, (funcp)execute_501, (funcp)execute_582, (funcp)execute_583, (funcp)execute_584, (funcp)execute_585, (funcp)execute_390, (funcp)execute_391, (funcp)execute_399, (funcp)execute_381, (funcp)execute_387, (funcp)execute_388, (funcp)execute_385, (funcp)execute_393, (funcp)execute_395, (funcp)execute_397, (funcp)execute_464, (funcp)execute_465, (funcp)execute_467, (funcp)execute_455, (funcp)execute_461, (funcp)execute_462, (funcp)execute_459, (funcp)execute_518, (funcp)execute_519, (funcp)execute_521, (funcp)execute_509, (funcp)execute_515, (funcp)execute_516, (funcp)execute_513, (funcp)execute_538, (funcp)execute_539, (funcp)execute_541, (funcp)execute_529, (funcp)execute_535, (funcp)execute_536, (funcp)execute_533, (funcp)execute_692, (funcp)execute_745, (funcp)execute_791, (funcp)execute_979, (funcp)execute_980, (funcp)execute_988, (funcp)execute_996, (funcp)execute_997, (funcp)execute_742, (funcp)execute_743, (funcp)execute_744, (funcp)execute_796, (funcp)execute_798, (funcp)execute_823, (funcp)execute_801, (funcp)execute_802, (funcp)execute_826, (funcp)execute_986, (funcp)execute_983, (funcp)execute_984, (funcp)execute_992, (funcp)execute_993, (funcp)execute_994, (funcp)execute_763, (funcp)execute_764, (funcp)execute_768, (funcp)execute_754, (funcp)execute_760, (funcp)execute_761, (funcp)execute_758, (funcp)execute_766, (funcp)execute_832, (funcp)execute_972, (funcp)execute_973, (funcp)execute_835, (funcp)execute_837, (funcp)execute_839, (funcp)execute_878, (funcp)execute_879, (funcp)execute_882, (funcp)execute_947, (funcp)execute_948, (funcp)execute_963, (funcp)execute_946, (funcp)execute_951, (funcp)execute_952, (funcp)execute_845, (funcp)execute_846, (funcp)execute_847, (funcp)execute_853, (funcp)execute_921, (funcp)execute_889, (funcp)execute_892, (funcp)execute_895, (funcp)execute_896, (funcp)execute_907, (funcp)execute_908, (funcp)execute_928, (funcp)execute_929, (funcp)execute_912, (funcp)execute_913, (funcp)execute_917, (funcp)execute_900, (funcp)execute_969, (funcp)execute_1022, (funcp)execute_1068, (funcp)execute_1256, (funcp)execute_1257, (funcp)execute_1265, (funcp)execute_1273, (funcp)execute_1274, (funcp)execute_1019, (funcp)execute_1020, (funcp)execute_1021, (funcp)execute_1073, (funcp)execute_1075, (funcp)execute_1100, (funcp)execute_1078, (funcp)execute_1079, (funcp)execute_1103, (funcp)execute_1263, (funcp)execute_1260, (funcp)execute_1261, (funcp)execute_1269, (funcp)execute_1270, (funcp)execute_1271, (funcp)execute_1109, (funcp)execute_1249, (funcp)execute_1250, (funcp)execute_1112, (funcp)execute_1114, (funcp)execute_1116, (funcp)execute_1155, (funcp)execute_1156, (funcp)execute_1159, (funcp)execute_1224, (funcp)execute_1225, (funcp)execute_1240, (funcp)execute_1223, (funcp)execute_1228, (funcp)execute_1229, (funcp)execute_1198, (funcp)execute_1166, (funcp)execute_1169, (funcp)execute_1172, (funcp)execute_1173, (funcp)execute_1184, (funcp)execute_1185, (funcp)execute_1205, (funcp)execute_1206, (funcp)execute_1189, (funcp)execute_1190, (funcp)execute_1194, (funcp)execute_1177, (funcp)execute_1246, (funcp)execute_1290, (funcp)execute_1291, (funcp)execute_1298, (funcp)execute_1299, (funcp)execute_1300, (funcp)execute_1301, (funcp)execute_1304, (funcp)execute_1305, (funcp)execute_1306, (funcp)execute_1307, (funcp)execute_1308, (funcp)execute_1309, (funcp)transaction_1, (funcp)transaction_5, (funcp)vhdl_transfunc_eventcallback, (funcp)transaction_42, (funcp)transaction_70, (funcp)transaction_119, (funcp)transaction_120, (funcp)transaction_123, (funcp)transaction_124, (funcp)transaction_130, (funcp)transaction_131, (funcp)transaction_134, (funcp)transaction_135, (funcp)transaction_136, (funcp)transaction_143, (funcp)transaction_157, (funcp)transaction_161, (funcp)transaction_168, (funcp)transaction_177, (funcp)transaction_271, (funcp)transaction_491, (funcp)transaction_492, (funcp)transaction_495, (funcp)transaction_496, (funcp)transaction_502, (funcp)transaction_503, (funcp)transaction_506, (funcp)transaction_507, (funcp)transaction_508, (funcp)transaction_515, (funcp)transaction_529, (funcp)transaction_533, (funcp)transaction_540, (funcp)transaction_549, (funcp)transaction_643, (funcp)transaction_744, (funcp)transaction_745, (funcp)transaction_748, (funcp)transaction_749, (funcp)transaction_755, (funcp)transaction_756, (funcp)transaction_759, (funcp)transaction_760, (funcp)transaction_761, (funcp)transaction_768, (funcp)transaction_782, (funcp)transaction_786, (funcp)transaction_793, (funcp)transaction_802, (funcp)transaction_896, (funcp)vlog_transfunc_eventcallback, (funcp)transaction_0, (funcp)transaction_2, (funcp)transaction_3, (funcp)transaction_4};
const int NumRelocateId= 356;

void relocate(char *dp)
{
	iki_relocate(dp, "xsim.dir/testbench_behav/xsim.reloc",  (void **)funcTab, 356);
	iki_vhdl_file_variable_register(dp + 875440);
	iki_vhdl_file_variable_register(dp + 875496);


	/*Populate the transaction function pointer field in the whole net structure */
}

void sensitize(char *dp)
{
	iki_sensitize(dp, "xsim.dir/testbench_behav/xsim.reloc");
}

	// Initialize Verilog nets in mixed simulation, for the cases when the value at time 0 should be propagated from the mixed language Vhdl net

void wrapper_func_0(char *dp)

{

	iki_vlog_schedule_transaction_signal_fast_vhdl_value_time_0(dp + 1146200, dp + 1143864, 0, 3, 0, 3, 4, 1);

}

void simulate(char *dp)
{
		iki_schedule_processes_at_time_zero(dp, "xsim.dir/testbench_behav/xsim.reloc");
	wrapper_func_0(dp);

	iki_execute_processes();

	// Schedule resolution functions for the multiply driven Verilog nets that have strength
	// Schedule transaction functions for the singly driven Verilog nets that have strength

}
#include "iki_bridge.h"
void relocate(char *);

void sensitize(char *);

void simulate(char *);

extern SYSTEMCLIB_IMP_DLLSPEC void local_register_implicit_channel(int, char*);
extern SYSTEMCLIB_IMP_DLLSPEC int xsim_argc_copy ;
extern SYSTEMCLIB_IMP_DLLSPEC char** xsim_argv_copy ;

int main(int argc, char **argv)
{
    iki_heap_initialize("ms", "isimmm", 0, 2147483648) ;
    iki_set_sv_type_file_path_name("xsim.dir/testbench_behav/xsim.svtype");
    iki_set_crvs_dump_file_path_name("xsim.dir/testbench_behav/xsim.crvsdump");
    void* design_handle = iki_create_design("xsim.dir/testbench_behav/xsim.mem", (void *)relocate, (void *)sensitize, (void *)simulate, (void*)0, 0, isimBridge_getWdbWriter(), 0, argc, argv);
     iki_set_rc_trial_count(100);
    (void) design_handle;
    return iki_simulate_design();
}
