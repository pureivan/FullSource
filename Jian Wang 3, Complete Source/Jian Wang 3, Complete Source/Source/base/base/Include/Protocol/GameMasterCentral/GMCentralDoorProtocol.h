//---------------------------------------------------------------------------
// ������Ե�����2 GameMasterCentral ������ͨ
// ��Ȩ����:       2006-2007 ��ɽ����(Kingsoft)
// ��������������: 2007-1-3 Խ��(wooy)
//---------------------------------------------------------------------------
// GameMasterCentral����Ϸ����֮��ĸ���Ӧ��ϵͳ֮�����ӵ�Э��ӿڡ�
// ��ЩЭ�鶼�����ı����ݰ���ʽ���ͣ����ݰ������һ���ֽڶ����ַ�����β��'\0'��
// ��Щ���ӷ�Ϊ���࣬һ�������Ĵ���ԭЭ�����ݰ��ı���һ���ǰ��ı����м���ת��
// ���ٴ��䡣
// GmWeb2.0�õ��Ǿ�GmWeb�ӿ�Э�飬���Э�鲻ͨ��������Э��֮�以�಻���ݡ�
//---------------------------------------------------------------------------
#ifndef __GAME_MASTER_CENTRAL_GMCENTRAL_DOOR_PROTOCOL_H__
#define __GAME_MASTER_CENTRAL_GMCENTRAL_DOOR_PROTOCOL_H__

struct GMCENTRAL_DOOR_PROTOCOL_PARAM
{
	//���ı�Э���и��ֶεķָ������Կո�Ϊ�ָ�����
	#define FIELD_SEPARATOR			' '
	//�ֶ����ֶ��������ֶ�ǰ׺��ʶ�ķָ�������ð�ŷָ���
	#define FIELD_PREFIX_SEPARATOR	':'
	//Э��ĵ�һ���ֶ�Ϊ����ؼ��֣����Ƕ�Ϊ�̶�����:8���ֽڣ������ַ�����β����
	#define	OF_KEYWORD_LEN			8
	//Э��ĵڶ����ֶ�Ϊ�����ؼ��֣����ǵĳ����Ϊ11���ֽڣ������ַ�����β��ռ12�ֽ�
	#define OPER_KEYWORD_MAX_LEN	12
};

//=====Э��ķ���ؼ���=====
struct OF_KEYWORD
{
	#define	OF_KEYWORD_LEN	8		//��Щ�ؼ��ֶ�Ϊ�̶�����:8���ֽ�
	#define OFKW_SYSTEM		"_SYSTEM_"	//����ϵͳ����
	#define OFKW_RET		"_RETURN_"	//������Ϣ(����������ݰ�)
	#define OFKW_SINFO		"SYS_INFO"	//ϵͳ��Ϣ����
	#define OFKW_SNCTRL		"S_N_CTRL"	//����ϵͳһ�����	
	#define OFKW_SSCTRL		"S_S_CTRL"	//����ϵͳ�������	
	#define OFKW_ANCTRL		"A_N_CTRL"	//�ʺ�һ�����
	#define OFKW_RNCTRL		"R_N_CTRL"	//��ɫһ�����
	#define OFKW_RSCTRL		"R_S_CTRL"	//��ɫ�������
	#define OFKW_RINFO		"ROL_INFO"	//��ɫ��Ϣ��ѯ
	#define OFKW_GSINFO		"GAM_INFO"	//��ȡ��Ϸ������Ϣ
	#define OFKW_GSCTRL		"GAM_CTRL"	//��Ϸ������Ϣ����	
	#define OFKW_GMCTRL		"G_M_CTRL"	//GM�ʺŽ�ɫ����
	#define OFKW_ASTINFO	"AST_INFO"	//������Ϣ
};

//-------------------------------------
//		����ϵͳ�����Ĳ���
//-------------------------------------
struct GMC_SYSTEM_OPERATION
{
	//���ڸ���GMC�����ӵĻ��������Ϣ��
	#define GMC_SO_CONNECT_INFO	"CONN_INFO"
		//GMC�����ܸ������������ʲô���ӣ���ȷ��֧���ڸ������Ͻ�����Щ������
		//��GMC������ĵ�һ����Ϣ�͸÷������Ϣ����ΪĿǰ�����ݾ�GMWeb2.0������GMC
		//�����һ����Ϣ����յ��Ĳ��������Ϣ����GMC�Ѹ������ж�Ϊ��GMWeb2.0���ӣ�
		//�����յ�����Ϣֻ�Ծ�GMWeb2.0�����ĸ�ʽ��������
		//����Ϣ�ĸ�ʽ���£�
		//_SYSTEM_ CONN_INFO SN:0-0 NAME:������ IDENT:ʶ���
		//��ʽ����˵����
		//������:	�������Ϊ31���ֽڳ���GMC��������������ʶ��ȷ��������ʲô���ӡ�
		//			GMC�����ܸ��������������ø����������ɵĲ�������������Ϊͬ��һ��
		//			��������
		//ʶ���:	Ϊ10���Ʊ�ʾ�ķ�0������������������ͬʱ��������ʶ��ţ����ֲ�ͬ
		//			��ͬ�����ӡ���������ͬ�����ӣ�ʶ��Ų�����ͬ����ͬ����������ʶ��
		//			�ſ�����ͬ��
};

#define	GMC_GROUP_NAME_ALL		"__ALL__"

//GM����Э��Ļ����ֶ�
//����Э���еĻ����ֶΣ��ڸ�ʽ�����Ƕ����ֶε���ǰ������ض���ǰ׺�ؼ��֣�����ϵͳ�����ݽ��п��ٵ�
//�������ͳһ��ʶ��ǰ׺�ؼ��ֶ���Ӣ�ķ��ű�ʾ�����ִ�Сд��ǰ׺�ؼ������ֶ����ݼ䶼��ð��:��Ϊ����š�
//ǰ׺�ؼ����Ϊ7���ַ������涨����һЩ�����ֶε�ǰ׺�ؼ��֡�
struct GMC_COMMON_FIELD_NAME
{
	//Э�����ˮ�ţ��������Ψһ�ı������ÿ��Э�飬�����ϵͳ��λ������Դ�봦����
	#define GMC_CF_SERIAL_NO	"SN"
		//��ʽ��SN:��ֵ1-��ֵ2
		//˵������ֵ1����ֵ2����ʮ��������������ÿ�������������ֵΪFFFFFFFF����32bit��ʾ���������
		//��ֵ1ΪGMC���ɣ����ҽ�GMC��ϵͳ����������ֵ�ĺ��塣��ֵ2λ�ɸ��ҽ�GMC��ϵͳ������������Ϣ
		//ʱ�������ɣ����ڱ�ʾ��ϵͳ�в�������Ϣ����ˮ�ţ�����ϵͳ����������֮���ƥ��ȡ�

	//��ʾ������Ŀ��������������Ϣ��Դ��Դ����
	#define GMC_CF_SVR_GROUP	"GROUP"
		//��ʽ��GROUP:������-������
		//˵�����������ͷ���������ʮ���ƷǸ�������������Ϊ0ʱ��ʾ������������������Ϊ0ʱ��ʾ�������
		//��GROUP:3-2��ʾ3��2����GROUP:2-1��ʾ2��1����GROUP:15-0��ʾ15��ȫ����GROUP:0-0��ʾȫ��ȫ����

	//���ַ������Ʊ�ʾ������Ŀ������
	#define GMC_CF_SVR_GROUP_NAME	"GROUPN"
	//��ʽ��GROUPN:��������
	//˵�������������ַ����������ڵ���31�ֽڣ��������ΪGMC_GROUP_NAME_ALL����ʾȫ����

	//����ʺ�������Ϊ��Ϸϵͳ֧�ֵĺϷ��ʺ���
	#define GMC_CF_ACCOUNT		"ACC"
		//��ʽ��ACC:�ʺ����ַ���
		//˵�����ʺ����ַ�������Ҫ�����ţ���������涨32���ֽڣ���̲�����4���ֽڡ�

	//��ҽ�ɫ������Ϊ��Ϸ�����й涨�ĺϷ���ɫ��
	#define GMC_CF_ROLE			"ROLE"
		//��ʽ��ROLE:��ɫ���ַ���
		//˵������ɫ���ַ�������Ҫ�����ţ����峤�Ⱥ͸�����Ϸ���������������йء�

	//����GM�����Ĳ���Ա���ʺ���
	#define GMC_CF_OPERATOR		"OPER"
		//��ʽ��OPER:����Ա�����ʺ����ַ���
		//˵������Щ����GM��Ҫ��Ȩ����Ҫ��������ָ������GM�����Ĳ���Ա�ʺš�

	//GM��ɫ��
	#define GMC_CF_GM_ROLE		"GM"
		//��ʽ��GM:��ɫ���ַ���
		//˵������ɫ���ַ�������Ҫ�����ţ����峤�Ⱥ͸�����Ϸ���������������й�

	//ѡ���
	#define GMC_CF_OPT			"OPT"
		//��ʽ��OPT:ON �� OPT:OFF

	//���ڱ����ı���Ϣ����Ϣ���ݣ���������䡢�������ݵ�
	#define GMC_CF_TEXT_DATA	"T_DATA"
		//��ʽ��T_DATA:�ı���Ϣ����-�ı���Ϣ����
		//˵�����ı���Ϣ����Ϊһ��ʮ������������Ϊ�����������ı���Ϣ�������ֽڼƵĳ��ȡ�
		//��Ϣ�ı����ɰ����ո����ŵȷ��š��ı���Ϣ����ֵ������֮���м��ŷָ���-��

	//���ڱ�����������Ϣ����Ϣ��������
	#define GMC_CF_BIN_DATA		"B_DATA"
		//��ʽ��B_DATA:��Ϣ������Ϣ����
		//˵������Ϣ����Ϊ�����ֽڳ���(unsigned short)��������Ϊ������������Ϣ�������ݿ飬
		//���ݿ��(���ֽڼ�)���ȼ�Ϊǰ����Ϣ���ȵ�ֵ����Ϣ��������Ϣ����֮���޼������
		//�������һ��3���ֽڳ��ȵ���Ϣ������ֶε��ܳ���Ϊ11���ֽڡ�

	//����Ĵ���������ɹ���ʧ�ܣ�
	#define GMC_CF_RESULT		"RESULT"
		//��ʽ��RESULT:SUCCESS �� RESULT:FAIL
};


#endif// #ifndef __GAME_MASTER_CENTRAL_GMCENTRAL_DOOR_PROTOCOL_H__