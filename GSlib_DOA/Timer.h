#ifndef SCORE_H_
#define SCORE_H_

class Timer {
public:
	//�R���X�g���N�^
	Timer(int timer = 6000);
	//�^�C�}�[�̏�����
	void initialize(int timer = 0);
	//�^�C�}�[�̌��Z
	void sub(int timer);
	//�^�C�}�[�̕`��
	void draw() const;
	//�^�C�}�[�̎擾
	int get() const;
	//�^�C�}�[�̃N���A
	void clear();

private:
	//�^�C�}�[
	int timer_ = 6000;


};

#endif