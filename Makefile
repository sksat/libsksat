INSTALL_DIR := /usr/include

install:
	@echo install libsksat to $(INSTALL_DIR) ...
	@cp -rf sksat $(INSTALL_DIR)
	@echo install finished.

uninstall:
	@echo uninstall to rm $(INSTALL_DIR)/sksat ...
	@rm -rf $(INSTALL_DIR)/sksat
	@echo uninstall finished.
