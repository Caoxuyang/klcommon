///
/// Ϊ������GS AI�ܹ����ּ��ݵĵ�AI��װ�࣬����һЩ��Ϣͨ�ŷ�װ��
/// AI�������á�
///
namespace MServer
{
	class CMSAIWrapper : public CMonsterAI
	{
	public:
		/// �����������������ǵ�һ�ε��ã���ζ��MS��û�д˹��︱������Ҫ���룻
		/// ������Ҫ���롣
		void OnBoring();

		/// ɾ������
		void OnDel();

		/// ����
		void OnReBorn();

		/// ���ܽ����ص�����Ҫ����Ϣ��MS
		BOOL OnSkillEnd( long lAddSub );

		/// ���ù���Ŀ�꣬���ݼ���ģ��DEBUFF�˺�
		void SetTarget( long type, const CGUID &guid );

		/// ����AI������Ϣ��MS
		void WakeUp();

		/// �ܵ��˺����ᷢ����Ϣ
		BOOL WhenBeenHurted( long type, const CGUID &guid, DWORD hurt );

		/// ������
		BOOL WhenBeenKilled( long type, const CGUID &guid );

	public:
		/// MS��������ƶ�
		void ReqMove( long dir );

		/// MS�������ʹ�ü���
		void ReqUseSkill( long skill_id, long skill_lvl, const CGUID &target_id );	

	private:
		/// ��־�Ƿ��ǵ�һ�δ���
		bool m_bFirstCreated;
	};
}